*** src/recommend.c.bak	Wed Apr  2 07:15:45 1997
--- src/recommend.c	Tue Jun 17 21:48:49 1997
***************
*** 23,29 ****
     { fprintf(stderr,"Please run this program via 'make recommend'\n");
       return EX_USAGE;
     }
-   strchr(mailspooldir,'\0')[-1]='\0';		     /* strip last character */
    for(p=checkf;*p;p++)
       if(!stat(*p,&stbuf)&&stbuf.st_mode&S_ISGID)
        { if(stbuf.st_mode&S_ISGID)
--- 23,28 ----
