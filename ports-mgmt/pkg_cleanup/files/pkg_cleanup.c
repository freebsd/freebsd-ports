#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <ctype.h>
#include <curses.h>
#include <dialog.h>
#include <errno.h>
#include <glob.h>
#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringlist.h>
#include <sysexits.h>
#include <unistd.h>

#if __FreeBSD_version < 900030
#define OLD_DIALOG
#endif

static glob_t	gl;	/* A cached list of all files in /var/db/pkg */
static StringList *sl;
static size_t	pathc;
static char		**pathv;
static bool 	uses_pkg;
static int		menulen=0;
static int		helpfile=-1;
static char		helpfname[]="/tmp/pkgcleanup.XXXX";

#ifdef OLD_DIALOG
typedef dialogMenuItem ListItem;
#else
typedef DIALOG_LISTITEM ListItem;
#endif
ListItem	*menu;
#ifdef OLD_DIALOG
#define ITEM_DATA		data
#define ITEM_PROMPT		prompt
#define ITEM_CHECKED	aux
#else
#define ITEM_DATA		help
#define ITEM_PROMPT		name
#define ITEM_CHECKED	state
#endif

bool check_pkg(void)
{
	if(WEXITSTATUS(system("TMPDIR=/dev/null "
						"ASSUME_ALWAYS_YES=1 "
						"PACKAGESITE=file:///nonexistent "
						"pkg info -x 'pkg(-devel)?$' "
						">/dev/null 2>&1")
				)==0)
		return true;
	return false;
}

void free_menu(void)
{
	int		i;

	if(menu) {
		for(i=0; i<menulen; i++) {
			if(menu[i].ITEM_DATA) {
				free(menu[i].ITEM_DATA);
				menu[i].ITEM_DATA=NULL;
			}
			if(menu[i].ITEM_PROMPT) {
				free(menu[i].ITEM_PROMPT);
				menu[i].ITEM_PROMPT=NULL;
			}
		}
		free(menu);
		menu=NULL;
		menulen=0;
	}
}

int blacklist(char *path, int operation)
{
	ENTRY		item;

	item.data=NULL;
	item.key=path;
	return(hsearch(item, operation)!=NULL);
}

char *read_desc(char *path)
{
	if(uses_pkg) {
		char newpath[MAXPATHLEN+1];
		char *p=NULL;
		char *np=NULL;
		FILE *pkg;
		char chunk[1024];
		size_t	cs, len=0;

		sprintf(newpath,"/usr/sbin/pkg query %%e \"%s\"", path);
		fflush(stdout);
		pkg=popen(newpath, "r");
		if(!pkg)
			return NULL;
		while((cs=fread(chunk, 1, sizeof(chunk), pkg))) {
			np=(char *)realloc(p, len+cs+1);
			if(!np) {
				pclose(pkg);
				free(p);
				return NULL;
			}
			p=np;
			memcpy(p+len, chunk, cs);
			len+=cs;
			p[len]=0;
		}
		pclose(pkg);
		if(len==0) {
			free(p);
			return NULL;
		}
		return p;
	}
	else {
		char *p;
		char newpath[MAXPATHLEN+1];
		FILE *file;
		struct stat	sb;

		sprintf(newpath,"/var/db/pkg/%s/+DESC",path);
		file=fopen(newpath, "r");
		if(file) {
			if(fstat(fileno(file), &sb)==0) {
				p=(char *)malloc(sb.st_size+1);
				if(p) {
					if(fread(p, sb.st_size, 1, file)==1) {
						fclose(file);
						p[sb.st_size]=0;
						return p;
					}
					free(p);
				}
			}
			fclose(file);
		}
	}
	return NULL;
}

#ifdef OLD_DIALOG
int fire(struct _dmenu_item *item)
{
	if(item->aux)
		item->aux=0;
	else
		item->aux=-1L;
	return(DITEM_SUCCESS);
}

void selected(struct _dmenu_item *item, int is_selected)
{
	char	path[MAXPATHLEN+1];
	int		maxx,maxy;

	if(is_selected) {
		getmaxyx(stdscr, maxy, maxx);
		draw_box(stdscr, 3, 2, 3, maxx-4, dialog_attr, border_attr);
		wattrset(stdscr, dialog_attr);
		mvwaddnstr(stdscr, 4, 4, (char *)item->data, maxx-6);
		wrefresh(stdscr);
		if(uses_pkg) {
			char	*desc=read_desc(item->prompt);
			lseek(helpfile, 0, SEEK_SET);
			if(desc) {
				write(helpfile, desc, strlen(desc));
				free(desc);
			}
			ftruncate(helpfile, lseek(helpfile, 0, SEEK_CUR));
		}
		else {
			sprintf(path,"/var/db/pkg/%s/+DESC",item->prompt);
			use_helpfile(path);
		}
	}
}

int checked(struct _dmenu_item *item)
{
	if(item->aux)
		return(TRUE);
	return(FALSE);
}
#endif

char *read_comment(char *path)
{
	if(uses_pkg) {
		char newpath[MAXPATHLEN+1];
		char *p=NULL;
		char *np=NULL;
		FILE *pkg;
		char chunk[1024];
		size_t	cs, len=0;

		sprintf(newpath,"/usr/sbin/pkg query %%c \"%s\"", path);
		fflush(stdout);
		pkg=popen(newpath, "r");
		if(!pkg)
			return strdup("");
		while((cs=fread(chunk, 1, sizeof(chunk), pkg))) {
			np=(char *)realloc(p, len+cs+1);
			if(!np) {
				pclose(pkg);
				free(p);
				return strdup("");
			}
			p=np;
			memcpy(p+len, chunk, cs);
			len+=cs;
			p[len]=0;
		}
		pclose(pkg);
		if(len==0) {
			free(p);
			return strdup("");
		}
		return p;
	}
	else {
		char		comment[80];
		FILE		*file;
		char		newpath[MAXPATHLEN+1];
		char		*p;

		/* Read +COMMENT */
		sprintf(newpath,"%s/+COMMENT",path);
		file=fopen(newpath,"r");
		if(file) {
			fgets(comment, sizeof(comment), file);
			fclose(file);
			/* Remove trailing whitespace */
			for(p=strchr(comment,0)-1; p>=comment; p--) {
				if(isspace(*p))
					*p=0;
				else
					break;
			}
			return strdup(comment);
		}
	}
	return strdup("");
}

/* Read +COMMENT, add to menu and blacklist */
int add_item(char *path, char *comment)
{
	char		*p;
	ListItem	*newmenu;

	if(blacklist(path,FIND))
		return(0);
	blacklist(path,ENTER);

	newmenu=(ListItem *)realloc(menu, sizeof(ListItem)*(menulen+1));
	if(newmenu==NULL)
		return(-1);
	menu=newmenu;

	p=strrchr(path,'/');
	if(p==NULL)
		p=path;
	else
		p++;

	menu[menulen].ITEM_PROMPT=strdup(p);
	menu[menulen].ITEM_CHECKED=0;
#ifdef OLD_DIALOG
	menu[menulen].title="";
	menu[menulen].checked=checked;
	menu[menulen].fire=fire;
	menu[menulen].selected=selected;
	menu[menulen].lbra='[';
	menu[menulen].mark='X';
	menu[menulen].rbra=']';
#else
	menu[menulen].text="";
#endif

	menu[menulen].ITEM_DATA=strdup(comment);
	menulen++;

	return(0);
}

void do_init_dialog(void)
{
#ifdef OLD_DIALOG
	init_dialog();
	use_shadow=FALSE;
#else
	init_dialog(stdin, stdout);
	dialog_state.use_shadow=FALSE;
#endif
}

int display_menu(void)
{
	int	ret=0;
	int	maxx,maxy;
	int	curr;

	do_init_dialog();
	getmaxyx(stdscr, maxy, maxx);
#ifdef OLD_DIALOG
	if(dialog_checklist("Welcome to pkg_cleanup.", "These are the leaf packages installed on your system\nChose the packages to deinstall. F1 will display the package description.\n\n\n", maxy, maxx, maxy-11, 0-menulen, menu, NULL))
		ret=-1;
#else
	dialog_vars.help_button=1;
	dialog_vars.item_help=1;
loop:
	switch(ret=dlg_checklist("Welcome to pkg_cleanup.", "These are the leaf packages installed on your system\nChose the packages to deinstall. Help will display the package description.", maxy-1, maxx, maxy-9, menulen, menu, " X", FLAG_CHECK, &curr)) {
		case DLG_EXIT_HELP: {
			char *p = read_desc(menu[curr].ITEM_PROMPT);
			if(p) {
				dialog_vars.help_button=0;
				dialog_msgbox(menu[curr].ITEM_DATA, p, maxy-4, maxx-4, TRUE);
				dialog_vars.help_button=1;
				free(p);
			}
			goto loop;
		}
		case 0:
			ret=0;
			break;
		default:
			ret=-1;
			break;
	}
	dialog_vars.help_button=0;
	dialog_vars.item_help=0;
#endif
	end_dialog();
	return(ret);
}

bool is_leaf_package(char *path)
{
	char	newpath[MAXPATHLEN+1];
	struct stat	sb;

	if(uses_pkg) {
		FILE	*pkg;
		char	val[32];
		long	v;

		sprintf(newpath,"/usr/sbin/pkg query \"%%#r%%k\" \"%s\"", path);
		fflush(stdout);
		pkg=popen(newpath,"r");
		if(pkg) {
			if(fgets(val, sizeof(val), pkg)!=NULL) {
				if(WEXITSTATUS(pclose(pkg))==0) {
					if(strtol(val, NULL, 10)==0)
							return true;
					return false;
				}
				else {
					blacklist(path,ENTER);
					return false;
				}
			}
		}
		blacklist(path,ENTER);
		pclose(pkg);
		return false;
	}
	else {
		sprintf(newpath,"%s/+REQUIRED_BY",path);
		if(stat(newpath,&sb)) {
			switch(errno) {
				case ENOENT:
					/* No +REQUIRED_BY, add to list */
					return true;
					break;
				default:
					/* All other errors, add to blacklist */
					blacklist(path,ENTER);
					break;
			}
		}
		else {
			if(sb.st_size==0)
				return true;
		}
		return false;
	}
}

/* Goes through the glob contents, looking for zero-length +REQUIRED-BY */
int read_pkglist(int loops)
{
	if(uses_pkg) {
		FILE	*pkg;
		char	line[1024];
		char	*p;

		do_init_dialog();
		dialog_msgbox(NULL, "Searching for leaves", 5, 23, FALSE);
		fflush(stdout);
		pkg=popen("/usr/sbin/pkg query -e \"%#r=0 && %k=0\" \"%n-%v\\t%c\"", "r");
		if(!pkg) {
			fputs("Error executing pkg.\n", stderr);
			return -1;
		}
		while(fgets(line, sizeof(line), pkg)!=NULL) {
			for(p=strchr(line, 0)-1; p>line && isspace(*p); p--)
				*p=0;
			p=strtok(line, "\t");
			p=strtok(NULL, "\0");
			add_item(line, p?p:"");
		}
		if(WEXITSTATUS(pclose(pkg)) && menulen==0) {
			fputs("pkg returned an error.\n", stderr);
			return -1;
		}
#ifdef OLD_DIALOG
		dialog_clear_norefresh();
#else
		dlg_clear();
#endif
	}
	else {
		int		p;
		int		maxx,maxy;
		int		lastgauge=-1;
		int		gauge;
		char	*comment;
#ifndef OLD_DIALOG
		int		pipepair[2];
		FILE	*read_pipe;
		FILE	*write_pipe;
#endif

		do_init_dialog();
		getmaxyx(stdscr, maxy, maxx);
		for(p=0;p<pathc;p++) {
			gauge=p*100/pathc;
			if(gauge != lastgauge) {
#ifdef OLD_DIALOG
				dialog_gauge(NULL, "Searching for leaves", maxy/2-1, maxx/2-12, 7, 24, gauge);
#else
				if(pipe(pipepair)!=0) {
					fputs("Cannot create pipe pair.\n", stderr);
					return(-1);
				}
				if((read_pipe=fdopen(pipepair[0], "r"))==NULL) {
					fputs("Cannot open read end of pipe pair.\n", stderr);
					return(-1);
				}
				dialog_state.pipe_input=read_pipe;
				if((write_pipe=fdopen(pipepair[1], "r"))==NULL) {
					fputs("Cannot open read end of pipe pair.\n", stderr);
					return(-1);
				}
				fprintf(write_pipe, "%d\n%c", gauge, 4);
				fclose(write_pipe);
				dialog_gauge("", "Searching for leaves", maxy/2-1, maxx/2-12, gauge);
				fclose(read_pipe);
#endif
				lastgauge=gauge;
			}
			if(is_leaf_package(pathv[p])) {
				comment = read_comment(pathv[p]);
				add_item(pathv[p], comment);
				free(comment);
			}
		}
#ifdef OLD_DIALOG
		dialog_gauge(NULL, "Searching for leaves", maxy/2-1, maxx/2-12, 7, 24, 100);
		dialog_clear_norefresh();
#else
		if(pipe(pipepair)!=0) {
			fputs("Cannot create pipe pair.\n", stderr);
			return(-1);
		}
		if((read_pipe=fdopen(pipepair[0], "r"))==NULL) {
			fputs("Cannot open read end of pipe pair.\n", stderr);
			return(-1);
		}
		dialog_state.pipe_input=read_pipe;
		if((write_pipe=fdopen(pipepair[1], "r"))==NULL) {
			fputs("Cannot open read end of pipe pair.\n", stderr);
			return(-1);
		}
		fprintf(write_pipe, "%d\n%c", 100, 4);
		fclose(write_pipe);
		dialog_gauge("", "Searching for leaves", maxy/2-1, maxx/2-12, 100);
		fclose(read_pipe);
		dlg_clear();
#endif
	}
	if(menulen==0) {
		if(loops)
			dialog_msgbox(NULL, "No new leaves found", 5, 23, TRUE);
		else
			dialog_msgbox(NULL, "No leaves found", 5, 19, TRUE);
		end_dialog();
		return(-1);
	}
	end_dialog();
	return(0);
}

int remove_ports(void)
{
	char	*cmd;
	char	**args;
	char	*env[1]={NULL};
	char	**p;
	int		i;
	int		delete_count=0;
	pid_t	child;
	int		status;
	size_t	st;

	args=(char **)malloc((menulen+4) * sizeof(char *));
	if(!args) {
		do_init_dialog();
		dialog_msgbox("ERROR", "Can not allocate memory for package list!", 5, 45, TRUE);
		end_dialog();
		return(-1);
	}
	p=args;
	if(uses_pkg) {
		*(p++)="/usr/sbin/pkg";
		*(p++)="delete";
		*(p++)="-y";
	}
	else {
		*(p++)="/usr/sbin/pkg_delete";
		*(p++)="-G";
	}
	for(i=0;i<menulen;i++) {
		if(menu[i].ITEM_CHECKED) {
			*(p++)=menu[i].ITEM_PROMPT;
			delete_count++;
		}
	}
	*(p)=NULL;
	if(!delete_count) {
		do_init_dialog();
		dialog_msgbox(NULL, "No packages selected", 5, 24, TRUE);
		end_dialog();
		free(args);
		return(-1);
	}
	/* Ensure stdio is "right" */
	if(!isendwin())
		endwin();
	child=vfork();
	if(child==0) {
		execve(args[0], args, env);
		fprintf(stderr,"ERROR: %d!\n",errno);
#ifdef OLD_DIALOG
		if(helpfile != -1) {
			close(helpfile);
			unlink(helpfname);
		}
#endif
		_exit(EXIT_FAILURE);
	}
	free(args);
	if(child==-1) {
		do_init_dialog();
		dialog_msgbox(NULL, "Can not fork()", 5, 18, TRUE);
		end_dialog();
		return(-1);
	}
	waitpid(child, &status, 0);
	/* On an error return, pause */
	if(WIFSIGNALED(status) || (WIFEXITED(status) && WEXITSTATUS(status))) {
		fputs("\n\nPress ENTER to continue... ",stderr);
		fgetln(stdin, &st);
	}

	return(0);
}

int keep_going(void)
{
	int ret;

	do_init_dialog();
	ret = !dialog_yesno(NULL,"Do you want to process the new leaves packages?",-1,-1);
	end_dialog();
	return(ret);
}

int glob_packages(void)
{
	if(uses_pkg) {
		FILE	*pkg;
		char	*line;
		char	*nline;
		size_t	len;
		int		ret;

		sl = sl_init();
		fflush(stdout);
		pkg = popen("/usr/sbin/pkg query \"%n-%v\"", "r");
		if(!pkg) {
			fputs("Unable to get list of packages\n",stderr);
			return EX_OSERR;
		}
		while((line = fgetln(pkg, &len))!=NULL) {
			if(len > 0 && line[len-1]=='\n')
				len--;
			nline = strndup(line, len);
			if(!nline) {
				fprintf(stderr, "Unable allocate memory for \"%.*s\" to list\n", (int)len, line);
				return EX_UNAVAILABLE;
			}
			if(sl_add(sl, nline)) {
				fprintf(stderr, "Unable to add package \"%s\" to list\n", nline);
				return EX_UNAVAILABLE;
			}
		}
		ret = pclose(pkg);
		if(WEXITSTATUS(ret)) {
			fprintf(stderr, "pkg exited with error %d\n", WEXITSTATUS(ret));
			return WEXITSTATUS(ret);
		}

		pathc = sl->sl_cur;
		pathv = sl->sl_str;
	}
	else {
		/* glob() package directories */
		if(glob("/var/db/pkg/*", GLOB_ERR, NULL, &gl)) {
			fputs("Unable to get list of packages\n",stderr);
			switch(errno) {
				case GLOB_NOSPACE:
					return(EX_UNAVAILABLE);
				case GLOB_ABORTED:
					return(EX_NOINPUT);
				case GLOB_NOMATCH:
					return(EX_NOINPUT);
			}
			return(EXIT_FAILURE);
		}
		pathc = gl.gl_pathc;
		pathv = gl.gl_pathv;
	}
	return 0;
}

/*
 * The hash table is to keep track of leaves which  have already been displayed
 * to the user.
 */
int main(int argc, char **argv)
{
	int			i;

	uses_pkg = check_pkg();

	i = glob_packages();
	if(i)
		return i;

	if(pathc==0) {
		fputs("No packages found.\n",stderr);
		return(EXIT_FAILURE);
	}

	/* Initialize space for blacklist hash table */
	if(hcreate(10000)==0) {
		fputs("Cannot create hash table.\n",stderr);
		return(EX_UNAVAILABLE);
	}

	/* Create temp help file for the description when using pkg on 8.x */
#ifdef OLD_DIALOG
	if(uses_pkg)
		helpfile=mkstemp(helpfname);
#endif

	i=0;
	do {
		if(read_pkglist(i++))
			break;
		if(display_menu())
			break;
		if(remove_ports())
			break;
		free_menu();
	} while(keep_going());

#ifdef OLD_DIALOG
	if(helpfile != -1) {
		close(helpfile);
		unlink(helpfname);
	}
#endif

	fputs("\nProgram Terminated Successfully\n",stderr);
	return(0);
}
