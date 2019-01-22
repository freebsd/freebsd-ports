--- src/map.c.orig	2018-10-06 11:14:40 UTC
+++ src/map.c
@@ -818,7 +818,7 @@ void ParseSidMapLine(Barnyard2Config *bc
 		{
                 case 0: /* sid */
                     t_sn.generator = 1;
-		    if( (t_sn.id = strtoul(idx, NULL, 10)) == ULONG_MAX)
+		    if( ((unsigned long)(t_sn.id = strtoul(idx, NULL, 10))) == ULONG_MAX)
 		    {
 			FatalError("[%s()], error converting integer [%s] for line [%s] \n",
 				   __FUNCTION__,
@@ -848,7 +848,7 @@ void ParseSidMapLine(Barnyard2Config *bc
 		{
 
 		case 0: /*gid */
-		    if( (t_sn.generator = strtoul(idx,NULL,10)) == ULONG_MAX)
+		    if( ((unsigned long)(t_sn.generator = strtoul(idx,NULL,10))) == ULONG_MAX)
 		    {
                         FatalError("[%s()], error converting integer [%s] for line [%s] \n",
                                    __FUNCTION__,
@@ -859,7 +859,7 @@ void ParseSidMapLine(Barnyard2Config *bc
 		    break;
 
 		case 1: /* sid */
-		    if( (t_sn.id = strtoul(idx, NULL, 10)) == ULONG_MAX)
+		    if( ((unsigned long)(t_sn.id = strtoul(idx, NULL, 10))) == ULONG_MAX)
 		    {
                         FatalError("[%s()], error converting integer [%s] for line [%s] \n",
                                    __FUNCTION__,
@@ -869,7 +869,7 @@ void ParseSidMapLine(Barnyard2Config *bc
 		    break;
 
 		case 2: /* revision */
-		    if( (t_sn.rev = strtoul(idx, NULL, 10)) == ULONG_MAX)
+		    if( ((unsigned long)(t_sn.rev = strtoul(idx, NULL, 10))) == ULONG_MAX)
 		    {
                         FatalError("[%s()], error converting integer [%s] for line [%s] \n",
                                    __FUNCTION__,
@@ -889,7 +889,7 @@ void ParseSidMapLine(Barnyard2Config *bc
 
 		case 4: /* priority */
 		    
-		    if( (t_sn.priority = strtoul(idx, NULL, 10)) == ULONG_MAX)
+		    if( (unsigned long)(t_sn.priority = strtoul(idx, NULL, 10)) == ULONG_MAX)
 		    {
                         FatalError("[%s()], error converting integer [%s] for line [%s] \n",
                                    __FUNCTION__,
@@ -1121,7 +1121,7 @@ void ParseGenMapLine(char *data)
         switch(i)
         {
 	case 0: /* gen */
-	    if( (t_sn.generator = strtoul(idx, NULL, 10)) == ULONG_MAX)
+	    if( (unsigned long)(t_sn.generator = strtoul(idx, NULL, 10)) == ULONG_MAX)
 	    {
 		FatalError("[%s()], error converting integer [%s] for line [%s] \n",
 			   __FUNCTION__,
@@ -1131,7 +1131,7 @@ void ParseGenMapLine(char *data)
 	    break;
 	    
 	case 1: /* sid */
-	    if( (t_sn.id = strtoul(idx, NULL, 10)) == ULONG_MAX)
+	    if( (unsigned long)(t_sn.id = strtoul(idx, NULL, 10)) == ULONG_MAX)
 	    {
 		FatalError("[%s()], error converting integer [%s] for line [%s] \n",
 			   __FUNCTION__,
