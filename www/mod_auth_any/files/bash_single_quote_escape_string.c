/* Escape special characters in the input string so that the bash
	shell will not interpolate them when the input string is withing
	single quotes.

   IN: null-terminated character array containing string to be interpolated
  OUT: newly allocate (using malloc) null-terminated character array
       containing the input string with the special characters properly
       escaped */
char* bash_single_quote_escape_string(const char *s) {
  /* used to count the length of the string and the number of single quotes */
  int str_len, sq_count;
  int s_pos, buf_pos; /* copy chars loop counter */
  /* used to hold the final result string */
  char *buf;
  const char *escapees = "\"'\\$~` \t|&;()<>";

  /* Count the single quotes.
	  LOOP INVARIANT: str_len < (number of chars in string 's')
      POSTCONDITION: sq_count == (number of single quotes in string 's') */
  for (str_len = 0, sq_count = 0; s[str_len] != '\0'; str_len++)
	 if (strchr(escapees, s[str_len]) != NULL)
		sq_count++;

  /* Allocate the memory for the final string.
	  Each ' (one char) will become \' (2 chars), so multiply by 2
     and don't forget to add 1 for terminating null. */
  buf = (char*) malloc(sizeof(char) * (str_len + 1 + sq_count * 2));

  /* Copy the chars of 's' into 'buf', turning each ' into \' */
  for (s_pos = 0, buf_pos = 0; s_pos < str_len; s_pos++) {
	 /* If we see a single quote, then put '\'' into 'buf' and advance
		 buf_pos 4 positions, else put the next char from 's' into 'buf'
		 and advance buf_pos 1 position. */
	 if(strchr(escapees, s[s_pos]) != NULL) {
		buf[buf_pos++] = '\\';
		buf[buf_pos++] = s[s_pos];
	 } else {
		buf[buf_pos++] = s[s_pos];
	 }
  }
  /* don't forget the null terminator */
  buf[buf_pos] = '\0';

  return buf;
}
