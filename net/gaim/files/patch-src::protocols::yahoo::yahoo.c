*** src/protocols/yahoo/yahoo.c.orig	Thu Jan 22 09:57:03 2004
--- src/protocols/yahoo/yahoo.c	Thu Jan 22 10:15:11 2004
***************
*** 20,25 ****
--- 20,26 ----
   * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
   *
   */
+ #include <limits.h>
  #include "internal.h"
  
  #include "account.h"
***************
*** 131,138 ****
--- 132,146 ----
  		while (pos + 1 < len) {
  			if (data[pos] == 0xc0 && data[pos + 1] == 0x80)
  				break;
+ 			if (x >= sizeof(key)-1) {
+ 				x++;
+ 				continue;
+ 
+ 			}
  			key[x++] = data[pos++];
  		}
+ 		if (x >= sizeof(key)-1)
+ 			x = 0;
  		key[x] = 0;
  		pos += 2;
  		pair->key = strtol(key, NULL, 10);
***************
*** 868,899 ****
  	}
  }
  
  #define OUT_CHARSET "utf-8"
  
  static char *yahoo_decode(const char *text)
  {
  	char *converted;
! 	char *p, *n, *new;
! 	
! 	n = new = g_malloc(strlen (text) + 1);
! 
! 	for (p = (char *)text; *p; p++, n++) {
  		if (*p == '\\') {
! 			sscanf(p + 1, "%3o\n", (int *)n);
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
  
  	return converted;
  }
  
  static void yahoo_process_mail(GaimConnection *gc, struct yahoo_packet *pkt)
  {
  	GaimAccount *account = gaim_connection_get_account(gc);
--- 876,941 ----
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
! 
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
  
  	return converted;
  }
  
+ 
  static void yahoo_process_mail(GaimConnection *gc, struct yahoo_packet *pkt)
  {
  	GaimAccount *account = gaim_connection_get_account(gc);
***************
*** 1903,1934 ****
  
  static void yahoo_web_pending(gpointer data, gint source, GaimInputCondition cond)
  {
  	GaimConnection *gc = data;
  	GaimAccount *account = gaim_connection_get_account(gc);
  	struct yahoo_data *yd = gc->proto_data;
! 	char buf[1024], buf2[256], *i = buf, *r = buf2;
! 	int len, o = 0;
  
  	len = read(source, buf, sizeof(buf));
! 	if (len <= 0  || strncmp(buf, "HTTP/1.0 302", strlen("HTTP/1.0 302"))) {
  		gaim_connection_error(gc, _("Unable to read"));
  		return;
  	}
! 	
! 	while ((i = strstr(i, "Set-Cookie: ")) && 0 < 2) {
! 		i += strlen("Set-Cookie: "); 
! 		for (;*i != ';'; r++, i++) {
! 			*r = *i;
! 		}
! 		*r=';';
! 		r++;
! 		*r=' ';
! 		r++;
! 		o++;
! 	}
! 	/* Get rid of that "; " */
! 	*(r-2) = '\0';
! 	yd->auth = g_strdup(buf2);
  	gaim_input_remove(gc->inpa);
  	close(source);
  	/* Now we have our cookies to login with.  I'll go get the milk. */
--- 1945,1974 ----
  
  static void yahoo_web_pending(gpointer data, gint source, GaimInputCondition cond)
  {
+ 	static const char http302[] = "HTTP/1.0 302";
+ 	static const char setcookie[] = "Set-Cookie: ";
  	GaimConnection *gc = data;
  	GaimAccount *account = gaim_connection_get_account(gc);
  	struct yahoo_data *yd = gc->proto_data;
! 	char buf[1024], *i = buf;
! 	int len;
! 	GString *s;
  
  	len = read(source, buf, sizeof(buf));
! 	if (len <= 0 || (len >= sizeof(http302)-1 &&
! 	    memcmp(http302, buf, sizeof(http302)-1) != 0)) {
  		gaim_connection_error(gc, _("Unable to read"));
  		return;
  	}
! 	s = g_string_sized_new(len);
! 	buf[len] = '\0';
! 	while ((i = strstr(i, setcookie)) != NULL) {
! 		i += sizeof(setcookie)-1;
! 		for (;*i != ';'; i++)
! 			g_string_append_c(s, *i);
! 		g_string_append(s, "; ");
! 	}
! 	yd->auth = g_string_free(s, FALSE);
  	gaim_input_remove(gc->inpa);
  	close(source);
  	/* Now we have our cookies to login with.  I'll go get the milk. */
***************
*** 1937,1943 ****
  			       yahoo_got_web_connected, gc) != 0) {
  		gaim_connection_error(gc, _("Connection problem"));
  		return;
! 	}	
  }
  
  static void yahoo_got_cookies(gpointer data, gint source, GaimInputCondition cond)
--- 1977,1983 ----
  			       yahoo_got_web_connected, gc) != 0) {
  		gaim_connection_error(gc, _("Connection problem"));
  		return;
! 	}
  }
  
  static void yahoo_got_cookies(gpointer data, gint source, GaimInputCondition cond)
***************
*** 1974,1988 ****
  	const char *c = buf;
  	char *d;
  	char name[64], value[64];
  	while ((c < (buf + len)) && (c = strstr(c, "<input "))) {
  		c = strstr(c, "name=\"") + strlen("name=\"");
! 		for (d = name; *c!='"'; c++, d++) 
  			*d = *c;
  		*d = '\0';
  		d = strstr(c, "value=\"") + strlen("value=\"");
  		if (strchr(c, '>') < d)
  			break;
! 		for (c = d, d = value; *c!='"'; c++, d++)
  			*d = *c;
  		*d = '\0';
  		g_hash_table_insert(hash, g_strdup(name), g_strdup(value));
--- 2014,2030 ----
  	const char *c = buf;
  	char *d;
  	char name[64], value[64];
+ 	int count = sizeof(name)-1;
  	while ((c < (buf + len)) && (c = strstr(c, "<input "))) {
  		c = strstr(c, "name=\"") + strlen("name=\"");
! 		for (d = name; *c!='"' && count; c++, d++, count--)
  			*d = *c;
  		*d = '\0';
+ 		count = sizeof(value)-1;
  		d = strstr(c, "value=\"") + strlen("value=\"");
  		if (strchr(c, '>') < d)
  			break;
! 		for (c = d, d = value; *c!='"' && count; c++, d++, count--)
  			*d = *c;
  		*d = '\0';
  		g_hash_table_insert(hash, g_strdup(name), g_strdup(value));
