--- config.sh.orig	Mon Nov 23 09:51:15 1998
+++ config.sh	Thu Dec 24 08:41:14 1998
@@ -56,20 +56,24 @@
     fi
 fi
 
+if [ `uname` = FreeBSD ]; then	# FreeBSD
+LIB=$USR_DIR/share/$TCB
+else
 LIB=$USR_DIR/lib/$TCB
+fi
 BIN=$USR_DIR/bin
 MAN=$USR_DIR/man/man1
 
 cat >> .config <<EOF
-CC=	gcc
+CC?=	gcc
 #CFLAGS= -Wall -O2 -g
-CFLAGS= -Wall -O2
+CFLAGS?= -Wall -O2
 #LDFLAGS=
 LDFLAGS= -s
 OBJS=	alloc.o child.o code.o disp.o fork.o init.o key.o menu.o \\
 	mode.o scroll.o shell.o str.o sub.o tc.o tcb.o vt.o
 EOF
-if which grep >/dev/null && make -v 2>&1|grep 'GNU Make' >/dev/null 2>&1 && which sed >/dev/null; then
+if which grep >/dev/null && gmake -v 2>&1|grep 'GNU Make' >/dev/null 2>&1 && which sed >/dev/null; then
     cat >> .config <<EOF
 PROT=	mode.P tc.P tcb.P
 
@@ -113,7 +117,7 @@
 
 cat > install.sh <<EOF
 #! /bin/sh
-cd src; make; cd ..	
+cd src; gmake; cd ..	
 echo 'Installing tcb:'
 mkdir -p \$1$BIN
 mkdir -p \$1$LIB
