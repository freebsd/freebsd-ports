 --- mandata.c.orig	Sun Aug 29 09:29:38 2004
 +++ mandata.c	Sun Aug 29 09:33:45 2004
 @@ -241,11 +241,11 @@
  	char buffer2[BUFFER_SIZE];
  	switch ((int)context->get_value("show_mode")) {
  	case 0:
 -		sprintf(buffer,"%s -T '%s manual page' -n GMan -e man ",
 +		sprintf(buffer,"%s -T '%s manual page' -n GMan -e man %s",
  				(char*)context->get_value("xterm_command"),
 -				get_display_name(buffer1));
 -		len = strlen(buffer);
 -		attach(buffer+len,man_path->GetPath(),file_name);
 +				get_display_name(buffer1), get_display_name(buffer1));
 +/*		len = strlen(buffer);
 +		attach(buffer+len,man_path->GetPath(),file_name); */
  		//g_warning(buffer);
  		if(!fork())
  		{
 @@ -256,9 +256,9 @@
  		break;
  	case 1:
  		sprintf(loc_name," ~/.gman.%s.ps ",get_display_name(buffer1));
 -		sprintf(buffer,"man -t ");
 -		len = strlen(buffer);
 -		attach(buffer+len,man_path->GetPath(),file_name);
 +		sprintf(buffer,"man -t %s", get_display_name(buffer1));
 +/*		len = strlen(buffer);
 +		attach(buffer+len,man_path->GetPath(),file_name); */
  		strcat(buffer," >> ");
  		strcat(buffer,loc_name);
  		strcat(buffer," ; ");
 @@ -306,7 +306,7 @@
  	case 2:
  		sprintf(loc_name," ~/.gman.%s.html ",get_display_name(buffer1));
  		//g_warning(loc_name);
 -		strcpy(buffer,"/usr/lib/cgi-bin/gman.pl ");
 +		strcpy(buffer,"/usr/local/www/cgi-bin/gman.pl ");
  		strcat(buffer," ");
  		strcat(buffer,get_section_name(buffer2));
  		strcat(buffer," ");
