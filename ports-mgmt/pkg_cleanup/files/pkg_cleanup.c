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

static glob_t	gl;	/* A cached list of all files in /var/db/pkg */
dialogMenuItem	*menu=NULL;
int				menulen=0;

void free_menu(void)
{
	int		i;

	if(menu) {
		for(i=0; i<menulen; i++) {
			if(menu[i].data) {
				free(menu[i].data);
				menu[i].data=NULL;
			}
			if(menu[i].prompt) {
				free(menu[i].prompt);
				menu[i].prompt=NULL;
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

/* Read +COMMENT, add to menu and blacklist */
int add_item(char *path)
{
	char				*p;
	char				comment[80];
	FILE				*comment_file;
	char				comment_path[MAXPATHLEN+1];
	dialogMenuItem		*newmenu;

	if(blacklist(path,FIND))
		return(0);
	blacklist(path,ENTER);
	comment[0]=0;

	newmenu=(dialogMenuItem*)realloc(menu, sizeof(dialogMenuItem)*(menulen+1));
	if(newmenu==NULL)
		return(-1);
	menu=newmenu;

	p=strrchr(path,'/');
	if(p==NULL)				/* Not possible */
		return(-1);

	menu[menulen].prompt=strdup(p+1);
	menu[menulen].title="";
	menu[menulen].checked=checked;
	menu[menulen].fire=fire;
	menu[menulen].selected=selected;
	menu[menulen].lbra='[';
	menu[menulen].mark='X';
	menu[menulen].rbra=']';
	menu[menulen].aux=0;

	/* Read +COMMENT */
	sprintf(comment_path,"%s/+COMMENT",path);
	comment_file=fopen(comment_path,"r");
	if(comment_file) {
		fgets(comment, sizeof(comment), comment_file);
		fclose(comment_file);
		/* Remove trailing whitespace */
		for(p=strchr(comment,0)-1; p>=comment; p--) {
			if(isspace(*p))
				*p=0;
			else
				break;
		}
	}
	menu[menulen].data=strdup(comment);
	menulen++;

	return(0);
}

int display_menu(void)
{
	int	ret=0;
	int		maxx,maxy;

	init_dialog();
	use_shadow=FALSE;
	getmaxyx(stdscr, maxy, maxx);
	if(dialog_checklist("Welcome to pkg_cleanup.", "These are the leaf packages installed on your system\nChose the packages to deinstall. F1 will display the package description.\n\n\n", maxy, maxx, maxy-11, 0-menulen, menu, NULL))
		ret=-1;
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

	init_dialog();
	getmaxyx(stdscr, maxy, maxx);
	for(p=0;p<gl.gl_pathc;p++) {
		gauge=p*100/gl.gl_pathc;
		if(gauge != lastgauge) {
			dialog_gauge(NULL, "Searching for leaves", maxy/2-1, maxx/2-12, 7, 24, gauge);
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
	dialog_gauge(NULL, "Searching for leaves", maxy/2-1, maxx/2-12, 7, 24, 100);
	dialog_clear_norefresh();
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
		init_dialog();
		dialog_msgbox("ERROR", "Can not allocate memory for package list!", 5, 45, TRUE);
		end_dialog();
		return(-1);
	}
	p=args;
	*(p++)="-G";
	for(i=0;i<menulen;i++) {
		if(menu[i].aux) {
			*(p++)=menu[i].prompt;
			delete_count++;
		}
	}
	*(p)=NULL;
	if(!delete_count) {
		init_dialog();
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
		init_dialog();
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

	init_dialog();
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

	fputs("Program Terminated Successfully\n",stderr);
	return(0);
}
