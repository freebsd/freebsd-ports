*** appl/ftp/ftp/gssapi.c.orig	Wed Dec 17 14:12:55 2003
--- appl/ftp/ftp/gssapi.c	Wed Dec 17 14:13:52 2003
***************
*** 228,239 ****
  	    gss_release_buffer(&min_stat, &export_name);
  	    goto out;
  	}
! 	name = realloc(export_name.value, export_name.length + 1);
  	if(name == NULL) {
  	    reply(500, "Out of memory");
  	    gss_release_buffer(&min_stat, &export_name);
  	    goto out;
  	}
  	name[export_name.length] = '\0';
  	gss_release_buffer(&min_stat, &export_name);
  	d->client_name = name;
--- 228,240 ----
  	    gss_release_buffer(&min_stat, &export_name);
  	    goto out;
  	}
! 	name = malloc(export_name.length + 1);
  	if(name == NULL) {
  	    reply(500, "Out of memory");
  	    gss_release_buffer(&min_stat, &export_name);
  	    goto out;
  	}
+ 	memcpy(name, export_name.value, export_name.length);
  	name[export_name.length] = '\0';
  	gss_release_buffer(&min_stat, &export_name);
  	d->client_name = name;
