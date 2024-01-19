PREFIX?=	/usr/local
BINDIR?=	${PREFIX}/bin
MANDIR?=	${PREFIX}/man/man

PROG=	v7sh
SRCS=   args.c blok.c builtin.c cmd.c ctype.c error.c expand.c \
	fault.c io.c macro.c main.c msg.c name.c print.c service.c \
	setbrk.c stak.c string.c test.c word.c xec.c

#CFLAGS+=	-DSYSIII
#CFLAGS+=	-DRENO
#CFLAGS+=	-DULTRIX

CWARNFLAGS?=	-ansi -Wbad-function-cast
WARNS?=	6
MK_WERROR=no
WFORMAT=0

.include <bsd.prog.mk>
