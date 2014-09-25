http://seclists.org/oss-sec/2014/q3/690

*** ../bash-20140912/parse.y	2014-08-26 15:09:42.000000000 -0400
--- parse.y	2014-09-24 22:47:28.000000000 -0400
***************
*** 2959,2962 ****
--- 2959,2964 ----
    word_desc_to_read = (WORD_DESC *)NULL;
  
+   eol_ungetc_lookahead = 0;
+ 
    current_token = '\n';		/* XXX */
    last_read_token = '\n';
