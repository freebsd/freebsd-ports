*** ./src/protocols/yahoo/yahoo.c.orig	Wed Apr  7 09:54:00 2004
--- src/protocols/yahoo/yahoo.c	Wed Apr  7 09:59:43 2004
***************
*** 895,924 ****
  	}
  }
  
  #define OUT_CHARSET "utf-8"
  
  static char *yahoo_decode(const char *text)
  {
  	char *converted;
! 	char *n, *new;
! 	const char *end, *p;
! 	int i;
! 
! 	n = new = g_malloc(strlen (text) + 1);
! 	end = text + strlen(text);
  
! 	for (p = text; p < end; p++, n++) {
  		if (*p == '\\') {
! 			sscanf(p + 1, "%3o\n", &i);
! 			*n = i;
! 			p += 3;
! 		}
! 		else
! 			*n = *p;
  	}
- 
  	*n = '\0';
- 
  	converted = g_convert(new, n - new, OUT_CHARSET, "iso-8859-1", NULL, NULL, NULL);
  	g_free(new);
  
--- 895,953 ----
  	}
  }
  
+ 
+ static void octal(const char **p, const char *end, unsigned char *n)
+ {
+ 	int i, c;
+ 
+ 	for (i = 0, c = 0; i < 3 && *p < end; ++i, ++*p) {
+ 		c <<= 3;
+ 		switch (**p) {
+ 		case '0': break;
+ 		case '1': c += 1; break;
+ 		case '2': c += 2; break;
+ 		case '3': c += 3; break;
+ 		case '4': c += 4; break;
+ 		case '5': c += 5; break;
+ 		case '6': c += 6; break;
+ 		case '7': c += 7; break;
+ 		default:
+ 			  if (i == 0) {
+ 				  *n = **p;
+ 				  ++*p;
+ 				  return;
+ 			  }
+ 			  c >>= 3;
+ 			  goto done;
+ 		}
+ 	}
+ done:
+ 	*n = (c > UCHAR_MAX) ? '?' : c;
+ 	return;
+ }
+ 
  #define OUT_CHARSET "utf-8"
  
  static char *yahoo_decode(const char *text)
  {
  	char *converted;
! 	unsigned char *n, *new;
! 	size_t len;
! 	const char *p, *end;
  
! 	len = strlen (text);
! 	p = text;
! 	end = &text[len];
! 	n = new = g_malloc(len + 1);
! 	while (p < end) {
  		if (*p == '\\') {
! 			++p;
! 			octal(&p, end, n);
! 		} else
! 			*n = *p++;
! 		++n;
  	}
  	*n = '\0';
  	converted = g_convert(new, n - new, OUT_CHARSET, "iso-8859-1", NULL, NULL, NULL);
  	g_free(new);
  
