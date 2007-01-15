--- scanconf.l.orig	Thu Sep 18 09:59:48 2003
+++ scanconf.l	Thu Dec 28 13:31:06 2006
@@ -88,11 +88,15 @@
 
 /* token names */
 ROOTDIR		[Rr]oot[Dd]ir
+CHROOTDIR	[Cc]h[Rr]oot[Dd]ir
+USERNAME	[Uu]ser[Nn]ame
+GROUPNAME	[Gg]roup[Nn]ame
 TIMEFMT		[Tt]ime[Ff]mt
 POLLING		[Pp]olling
 SAVING		[Ss]aving
 TIMEOUT		[Tt]imeout
 RETRIES		[Rr]etries
+OMULSTATES	[Oo]bject[Mm]ultiple[Ss]tates
 
 GROUP		[Gg]roup
 PERMIT		[Pp]ermit
@@ -111,6 +115,8 @@
 
 OBJECT		[Oo]bject
 ADDRESS		[Aa]ddress
+SRCADDRESS	[Ss]rc[Aa]ddress
+BINDADDRESS	[Bb]ind[Aa]ddress
 DESCRIPTION	[Dd]escription|[Cc]omment
 SERVICE		[Ss]ervice
 INTERFACE	[Ii]nterface
@@ -144,11 +150,13 @@
 V2		[Vv]2
 
 TRAP		[Tt]rap
+TRAPBINDADDRESS	[Tt]rap[Bb]ind[Aa]ddress
 SOURCECHECK	[Ss]ource[Cc]heck
 COMMUNITY	[Cc]ommunity
 ENTERPRISE	[Ee]nterprise
 SPECIFIC	[Ss]pecific
 GENERIC		GENERIC|[Gg]eneric
+IGNORESTATE     [Ii]gnore[Ss]tate
 
 LETTER		[a-zA-Z]
 DIGIT		[0-9]
@@ -186,6 +194,12 @@
 
 {ROOTDIR}	{	return TOKEN_ROOTDIR;	}
 
+{USERNAME}	{	return TOKEN_USERNAME;	}
+
+{GROUPNAME}	{	return TOKEN_GROUPNAME;	}
+
+{CHROOTDIR}	{	return TOKEN_CHROOTDIR;	}
+
 {TIMEFMT}	{	return TOKEN_TIMEFMT;	}
 
 {POLLING}	{	return TOKEN_POLLING;	}
@@ -196,6 +210,8 @@
 
 {RETRIES}	{	return TOKEN_RETRIES;	}
 
+{OMULSTATES}	{	return TOKEN_OMULSTATES; }
+
 {GROUP}		{	return TOKEN_GROUP;	}
 
 {PERMIT}	{	return TOKEN_PERMIT;	}
@@ -224,6 +240,10 @@
 
 {ADDRESS}	{	return TOKEN_ADDRESS;	}
 
+{SRCADDRESS}	{	return TOKEN_SRCADDRESS; }
+
+{BINDADDRESS}	{	return TOKEN_BINDADDRESS; }
+
 {DESCRIPTION}	{	return TOKEN_DESCRIPTION; }
 
 {SERVICE}	{	return TOKEN_SERVICE;	}
@@ -286,6 +306,8 @@
 
 {TRAP}		{	return TOKEN_TRAP;	}
 
+{TRAPBINDADDRESS}	{	return TOKEN_TRAPBINDADDRESS;	}
+
 {SOURCECHECK}	{	return TOKEN_SOURCECHECK; }
 
 {COMMUNITY}	{	return TOKEN_COMMUNITY;	}
@@ -295,6 +317,8 @@
 {SPECIFIC}	{	return TOKEN_SPECIFIC;	}
 
 {GENERIC}	{	return TRAP_GENERIC;	}
+
+{IGNORESTATE}	{	return TOKEN_IGNORESTATE; }
 
 \${LETTER}({LETTER}|{DIGIT}|_)+(\.{DIGIT}+)*	{
 			yylval.string = &yytext[1];
