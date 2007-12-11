--- src/gnome-cmd-advrename-lexer.l.orig	2007-12-07 01:47:10.000000000 +0100
+++ src/gnome-cmd-advrename-lexer.l	2007-12-07 01:49:09.000000000 +0100
@@ -85,8 +85,8 @@
                                         case 'p' : *s++ = PARENT_DIR; break;
                                       }
                                     
-                                      *((int *) s)++ = --from;
-                                      *((int *) s)++ = length;
+                                      *s++ = --from;
+                                      *s++ = length;
                                     }
 
                                     fname_template_size -= sizeof(char)+2*sizeof(int);
@@ -99,7 +99,7 @@
 				    precision = -1;
                                     sscanf(yytext+3,"%d",&precision);
                                     *s++ = COUNTER;
-                                    *((int *) s)++ = precision<MAX_PRECISION ? precision : MAX_PRECISION;
+                                    *s++ = precision<MAX_PRECISION ? precision : MAX_PRECISION;
                                     fname_template_size -= sizeof(char)+sizeof(int);
                                   }
                                 }
@@ -117,8 +117,8 @@
                                       case 'p' : *s++ = PARENT_DIR; break;
                                     }
                                     
-                                    *((int *) s)++ = 0;
-                                    *((int *) s)++ = -1;
+                                    *s++ = 0;
+                                    *s++ = -1;
 
                                     fname_template_size -= sizeof(char)+2*sizeof(int);
                                   }
@@ -128,7 +128,7 @@
                                   if (fname_template_size>1+sizeof(int))
                                   {
                                     *s++ = COUNTER;
-                                    *((int *) s)++ = -1;
+                                    *s++ = -1;
                                     fname_template_size -= sizeof(char)+sizeof(int);
                                   }
                                 }
@@ -260,8 +260,8 @@
     switch (*src)
     {
       case NAME      : ++src;
-                       from = *((int *) src)++;
-		       length = *((int *) src)++;
+                       from = *src++;
+		       length = *src++;
 		       mksubstr(name_len,&from,&length);
 		       if (length<=NAME_MAX-(dest-fmt))
 		       {
@@ -271,8 +271,8 @@
 		       break;
 
       case EXTENSION : ++src;
-                       from = *((int *) src)++;
-		       length = *((int *) src)++;
+                       from = *src++;
+		       length = *src++;
 		       mksubstr(ext_len,&from,&length);
 		       if (length<=NAME_MAX-(dest-fmt))
 		       {
@@ -282,8 +282,8 @@
 		       break;
 
       case FULL_NAME : ++src;
-                       from = *((int *) src)++;
-		       length = *((int *) src)++;
+                       from = *src++;
+		       length = *src++;
 		       mksubstr(full_name_len,&from,&length);
 		       if (length<=NAME_MAX-(dest-fmt))
 		       {
@@ -293,8 +293,8 @@
 		       break;
 
       case PARENT_DIR: ++src;
-                       from = *((int *) src)++;
-		       length = *((int *) src)++;
+                       from = *src++;
+		       length = *src++;
 		       mksubstr(parent_dir_len,&from,&length);
 		       if (length<=NAME_MAX-(dest-fmt))
 		       {
@@ -304,7 +304,7 @@
 		       break;
 
       case COUNTER   : ++src;
-                       precision = *((int *) src)++;
+                       precision = *src++;
 		       if (precision!=-1)
 		         sprintf(custom_counter_fmt,"%%0%ilu",precision);
                        dest += snprintf(dest,NAME_MAX-(dest-fmt),(precision==-1 ? counter_fmt : custom_counter_fmt),counter);
