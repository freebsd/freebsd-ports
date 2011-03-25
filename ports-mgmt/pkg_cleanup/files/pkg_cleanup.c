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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#if __FreeBSD_version < 900030
#define OLD_DIALOG
#endif

static glob_t	gl;	/* A cached list of all files in /var/db/pkg */
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

int				menulen=0;

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
		sprintf(path,"/var/db/pkg/%s/+DESC",item->prompt);
		use_helpfile(path);
	}
}

int checked(struct _dmenu_item *item)
{
	if(item->aux)
		return(TRUE);
	return(FALSE);
}
#endif

/* Read +COMMENT, add to menu and blacklist */
int add_item(char *path)
{
	char		*p;
	char		comment[80];
	FILE		*file;
	char		newpath[MAXPATHLEN+1];
	ListItem	*newmenu;

	if(blacklist(path,FIND))
		return(0);
	blacklist(path,ENTER);
	comment[0]=0;

	newmenu=(ListItem *)realloc(menu, sizeof(ListItem)*(menulen+1));
	if(newmenu==NULL)
		return(-1);
	menu=newmenu;

	p=strrchr(path,'/');
	if(p==NULL)				/* Not possible */
		return(-1);

	menu[menulen].ITEM_PROMPT=strdup(p+1);
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
	}
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
			char *p;
			char newpath[MAXPATHLEN+1];
			FILE *file;
			struct stat	sb;

			/* READ +DESC */
			sprintf(newpath,"/var/db/pkg/%s/+DESC",menu[curr].ITEM_PROMPT);
			file=fopen(newpath, "r");
			if(file) {
				if(fstat(fileno(file), &sb)==0) {
					p=(char *)malloc(sb.st_size+1);
					if(p) {
						if(fread(p, sb.st_size, 1, file)==1) {
							p[sb.st_size]=0;
							dialog_vars.help_button=0;
							dialog_msgbox(menu[curr].ITEM_DATA, p, maxy-4, maxx-4, TRUE);
							dialog_vars.help_button=1;
						}
						free(p);
					}
				}
				fclose(file);
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

/* Goes through the glob contents, looking for zero-length +REQUIRED-BY */
int read_pkglist(int loops)
{
	char		path[MAXPATHLEN+1];
	int		p;
	struct stat	sb;
	int		maxx,maxy;
	int		lastgauge=-1;
	int		gauge;
#ifndef OLD_DIALOG
	int		pipepair[2];
	FILE	*read_pipe;
	FILE	*write_pipe;
#endif

	do_init_dialog();
	getmaxyx(stdscr, maxy, maxx);
	for(p=0;p<gl.gl_pathc;p++) {
		gauge=p*100/gl.gl_pathc;
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
			dialog_gauge(NULL, "Searching for leaves", maxy/2-1, maxx/2-12, gauge);
			fclose(read_pipe);
#endif
			lastgauge=gauge;
		}
		sprintf(path,"%s/+REQUIRED_BY",gl.gl_pathv[p]);
		if(stat(path,&sb)) {
			switch(errno) {
				case ENOENT:
					/* No +REQUIRED_BY, add to list */
					add_item(gl.gl_pathv[p]);
					break;
				default:
					/* All other errors, add to blacklist */
					blacklist(gl.gl_pathv[p],ENTER);
					break;
			}
		}
		else {
			if(sb.st_size==0)
				add_item(gl.gl_pathv[p]);
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
	dialog_gauge(NULL, "Searching for leaves", maxy/2-1, maxx/2-12, 100);
	fclose(read_pipe);
	dlg_clear();
#endif
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
	char	**args;
	char	*env[1]={NULL};
	char	**p;
	int		i;
	int		delete_count=0;
	pid_t	child;
	int		status;

	args=(char **)malloc((menulen+2) * sizeof(char *));
	if(!args) {
		do_init_dialog();
		dialog_msgbox("ERROR", "Can not allocate memory for package list!", 5, 45, TRUE);
		end_dialog();
		return(-1);
	}
	p=args;
	*(p++)="-G";
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
		execve("/usr/sbin/pkg_delete", args, env);
		fprintf(stderr,"ERROR: %d!\n",errno);
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
		fgetln(stdin, &i);
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

/*
 * The hash table is to keep track of leaves which  have already been displayed
 * to the user.
 */
int main(int argc, char **argv)
{
	char		**pathv;
	struct stat	sb;
	int			loops=0;

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

	if(gl.gl_pathc==0) {
		fputs("No packages found.\n",stderr);
		return(EXIT_FAILURE);
	}

	/* Initialize space for blacklist hash table */
	if(hcreate(1000)==0) {
		fputs("Cannot create hash table.\n",stderr);
		return(EX_UNAVAILABLE);
	}

	do {
		if(read_pkglist(loops++))
			break;
		if(display_menu())
			break;
		if(remove_ports())
			break;
		free_menu();
	} while(keep_going());

	fputs("\nProgram Terminated Successfully\n",stderr);
	return(0);
}
