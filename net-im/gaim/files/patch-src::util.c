*** src/util.c.orig	Fri Jan  9 22:04:56 2004
--- src/util.c	Thu Jan 22 08:26:14 2004
***************
*** 247,270 ****
  /**************************************************************************
   * Quoted Printable Functions
   **************************************************************************/
! void
! gaim_quotedp_decode(const char *str, char **ret_str, int *ret_len)
  {
! 	char *p, *n, *new;
  
! 	n = new = g_malloc(strlen (str) + 1);
  
! 	for (p = (char *)str; *p; p++, n++) {
  		if (*p == '=') {
! 			sscanf(p + 1, "%2x\n", (int *)n);
! 			p += 2;
! 		}
! 		else if (*p == '_')
  			*n = ' ';
  		else
  			*n = *p;
  	}
- 
  	*n = '\0';
  
  	if (ret_len)
--- 247,317 ----
  /**************************************************************************
   * Quoted Printable Functions
   **************************************************************************/
! static void hex(const char **p, const char *end, unsigned char *n)
  {
! 	int i, c;
  
! 	for (i = 0, c = 0; i < 2 && *p < end; ++i, ++*p) {
! 		c <<= 4;
! 		switch (**p) {
! 		case '0': break;
! 		case '1': c += 1; break;
! 		case '2': c += 2; break;
! 		case '3': c += 3; break;
! 		case '4': c += 4; break;
! 		case '5': c += 5; break;
! 		case '6': c += 6; break;
! 		case '7': c += 7; break;
! 		case '8': c += 8; break;
! 		case '9': c += 9; break;
! 		case 'a': c += 10; break;
! 		case 'b': c += 11; break;
! 		case 'c': c += 12; break;
! 		case 'd': c += 13; break;
! 		case 'e': c += 14; break;
! 		case 'f': c += 15; break;
! 		case 'A': c += 10; break;
! 		case 'B': c += 11; break;
! 		case 'C': c += 12; break;
! 		case 'D': c += 13; break;
! 		case 'E': c += 14; break;
! 		case 'F': c += 15; break;
! 		default:
! 			  if (i == 0) {
! 				  *n = **p;
! 				  ++*p;
! 				  return;
! 			  }
! 			  c >>= 4;
! 			  goto done;
! 		}
! 	}
! done:
! 	*n = (c > UCHAR_MAX) ? '?' : c;
! 	return;
! }
  
! void
! gaim_quotedp_decode(const char *str, char **ret_str, int *ret_len)
! {
! 	const char *p, *end;
! 	unsigned char *n, *new;
! 	size_t len;
! 
! 	len = strlen (str);
! 	n = new = g_malloc(len + 1);
! 	p = str;
! 	end = &p[len];
! 	while (p < end) {
  		if (*p == '=') {
! 			++p;
! 			hex(&p, end, n);
! 		} else if (*p == '_')
  			*n = ' ';
  		else
  			*n = *p;
+ 		++n;
  	}
  	*n = '\0';
  
  	if (ret_len)
***************
*** 1962,1968 ****
  			   char **ret_path)
  {
  	char scan_info[255];
! 	char port_str[5];
  	int f;
  	const char *turl;
  	char host[256], path[256];
--- 2009,2015 ----
  			   char **ret_path)
  {
  	char scan_info[255];
! 	char port_str[6];
  	int f;
  	const char *turl;
  	char host[256], path[256];
***************
*** 1982,1997 ****
  	}
  
  	g_snprintf(scan_info, sizeof(scan_info),
! 			   "%%[%s]:%%[%s]/%%[%s]", addr_ctrl, port_ctrl, page_ctrl);
  
  	f = sscanf(url, scan_info, host, port_str, path);
  
  	if (f == 1)
  	{
  		g_snprintf(scan_info, sizeof(scan_info),
! 				   "%%[%s]/%%[%s]",
  				   addr_ctrl, page_ctrl);
  		f = sscanf(url, scan_info, host, path);
  		g_snprintf(port_str, sizeof(port_str), "80");
  	}
  
--- 2029,2049 ----
  	}
  
  	g_snprintf(scan_info, sizeof(scan_info),
! 			   "%%255[%s]:%%5[%s]/%%255[%s]", addr_ctrl, port_ctrl, page_ctrl);
! 	addr_ctrl[sizeof(addr_ctrl)-1] = '\0';
! 	port_ctrl[sizeof(port_ctrl)-1] = '\0';
! 	page_ctrl[sizeof(page_ctrl)-1] = '\0';
  
  	f = sscanf(url, scan_info, host, port_str, path);
  
  	if (f == 1)
  	{
  		g_snprintf(scan_info, sizeof(scan_info),
! 				   "%%255[%s]/%%255[%s]",
  				   addr_ctrl, page_ctrl);
  		f = sscanf(url, scan_info, host, path);
+ 		addr_ctrl[sizeof(addr_ctrl)-1] = '\0';
+ 		page_ctrl[sizeof(page_ctrl)-1] = '\0';
  		g_snprintf(port_str, sizeof(port_str), "80");
  	}
  
***************
*** 2081,2089 ****
  static size_t
  parse_content_len(const char *data, size_t data_len)
  {
! 	size_t content_len = 0;
  
! 	sscanf(data, "Content-Length: %d", (int *)&content_len);
  
  	return content_len;
  }
--- 2133,2146 ----
  static size_t
  parse_content_len(const char *data, size_t data_len)
  {
! 	int content_len = 0;
! 	char *tmp;
  
! 	tmp = g_malloc(data_len + 1);
! 	memcpy(tmp, data, data_len);
! 	tmp[data_len] = '\0';
! 	sscanf(tmp, "Content-Length: %d", &content_len);
! 	g_free(tmp);
  
  	return content_len;
  }
