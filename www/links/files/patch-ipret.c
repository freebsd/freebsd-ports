--- ipret.c.orig	Fri Aug 29 13:05:17 2003
+++ ipret.c	Fri Feb 20 17:12:11 2004
@@ -411,7 +411,7 @@
 		case VARIABLE:
 			zrusit=(lns*)pom->argument;
 			if(zrusit)
-			{	if(zrusit->value==CIntMETFUN)
+			{	if(zrusit->value==CIntMETFUN&&zrusit->handler)
 				{	delarg((abuf*)zrusit->handler,context);
 					js_mem_free(zrusit); /* Kdyz zustane trcet na zasobniku
 						* interni funkce nebo metoda, tak ji je potreba znicit, stejne
