*** src/util.c.orig	Tue Jan 13 14:49:00 2004
--- src/util.c	Tue Jan 13 14:49:11 2004
***************
*** 2081,2089 ****
  static size_t
  parse_content_len(const char *data, size_t data_len)
  {
! 	size_t content_len = 0;
  
! 	sscanf(data, "Content-Length: %d", (int *)&content_len);
  
  	return content_len;
  }
--- 2081,2094 ----
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
