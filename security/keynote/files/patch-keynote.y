--- keynote-orig.y	Wed Jun 14 08:28:23 2000
+++ keynote.y	Wed May 28 14:47:32 2003
@@ -90,17 +90,17 @@
              | PRIVATEKEY { keynote_exceptionflag = keynote_donteval = 0; }
                         STRING { keynote_lex_remove($3);
 			         keynote_privkey = $3;
-			       }
+			       };
     
 keypredicate: /* Nothing */   { keynote_returnvalue = 0;
                                 return 0; 
                               }
        | notemptykeypredicate { keynote_returnvalue = $1;
 				return 0;
-                              }
+                              };
 
 notemptykeypredicate:  key     { $$ = $1; }
-       		     | keyexp  { $$ = $1; }
+       		     | keyexp  { $$ = $1; };
 
 keyexp: notemptykeypredicate AND { if (($1 == 0) && !keynote_justrecord)
                                      keynote_donteval = 1;
@@ -137,7 +137,7 @@
 			      $$ = get_kth($1);
 			    else
 			      $$ = 0;
-			  }  /* K-th */
+			  };  /* K-th */
 
 keylist: key
 	    { /* Don't do anything if we're just recording */ 
@@ -154,7 +154,7 @@
 		  keynote_kth_array[$1]++;
 
 	      keylistcount++;
-            }
+            };
 
 key: str        {
 		   if (keynote_donteval)
@@ -192,10 +192,10 @@
 				 break;
 			 }
 		   }
-                 }
+                 };
 
 localinit: /* Nothing */
-         | localconstants
+         | localconstants;
 
 localconstants: VARIABLE EQQ STRING 
 	  {
@@ -264,12 +264,12 @@
 
 	    if (i != RESULT_TRUE)
 	      return -1;
-	  } localconstants
+	  } localconstants ;
 
 program: prog { 
 	        keynote_returnvalue = $1;
 		return 0;
-	      }
+	      };
 
 prog:   /* Nada */ { $$ = 0; }
        | notemptyprog {
@@ -284,7 +284,7 @@
 			$$ = $1;
 		      else
 			$$ = $4;
-                    } 
+                    };
 
 notemptyprog: expr HINT afterhint
               {
@@ -299,7 +299,7 @@
 		  $$ = keynote_current_session->ks_values_num - 1;
 		else
 		  $$ = 0;
-	      }
+	      };
 
 afterhint: str {  if (keynote_exceptionflag || keynote_donteval)
 		    $$ = 0;
@@ -314,7 +314,7 @@
 		      free($1);
 		  }
                 }
-         | OPENBLOCK prog CLOSEBLOCK { $$ = $2; }
+         | OPENBLOCK prog CLOSEBLOCK { $$ = $2; };
 
 
 expr:     OPENPAREN expr CLOSEPAREN 	{ $$ = $2; }
@@ -333,19 +333,19 @@
 	| floatexp			{ $$ = $1; }
 	| stringexp 			{ $$ = $1; }
         | TRUE	  		        { $$ = 1; }
-        | FALSE	  		        { $$ = 0; }
+        | FALSE	  		        { $$ = 0; };
 
 numexp:	  numex LT numex { $$ = $1 < $3; }
 	| numex GT numex { $$ = $1 > $3; }
 	| numex EQ numex { $$ = $1 == $3; }
 	| numex LE numex { $$ = $1 <= $3; }
 	| numex GE numex { $$ = $1 >= $3; }
-	| numex NE numex { $$ = $1 != $3; }
+	| numex NE numex { $$ = $1 != $3; };
 
 floatexp: floatex LT floatex { $$ = $1 < $3; }
 	| floatex GT floatex { $$ = $1 > $3; }
 	| floatex LE floatex { $$ = $1 <= $3; }
-	| floatex GE floatex { $$ = $1 >= $3; }
+	| floatex GE floatex { $$ = $1 >= $3; };
 
 numex:	  numex PLUS numex  { $$ = $1 + $3; }
 	| numex MINUS numex { $$ = $1 - $3; }
@@ -383,7 +383,7 @@
 						$$ = (int) floor(atof($2));
 					      free($2);
 					  }
-					}
+					};
 
 floatex:  floatex PLUS floatex  	{ $$ = ($1 + $3); }
 	| floatex MINUS floatex 	{ $$ = ($1 - $3); }
@@ -417,7 +417,7 @@
 						$$ = atof($2);
 					      free($2);
 					  }
-	                                }
+	                                };
 
 stringexp: str EQ str {
                         if (keynote_exceptionflag || keynote_donteval)
@@ -578,7 +578,7 @@
 		      free($1);
 		  }
 	      }
-	    }
+	    };
 
 str: str DOTT str    {  if (keynote_exceptionflag || keynote_donteval)
 			  $$ = (char *) NULL;
@@ -604,7 +604,7 @@
 			      return -1;
 			}
 		      }
-	| strnotconcat { $$ = $1; }
+	| strnotconcat { $$ = $1; };
 
 strnotconcat: STRING 	                { $$ = $1; }
         | OPENPAREN str CLOSEPAREN 	{ $$ = $2; }
@@ -659,7 +659,7 @@
 				if (keynote_lex_add($$, LEXTYPE_CHAR) == -1)
 				  return -1;
 			    }
-			 }
+			 };
 %%
 
 /*
