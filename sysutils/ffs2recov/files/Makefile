# $FreeBSD$

PROG=	ffs2recov
SRCS=	main.c block.c inode.c io.c super.c
MAN=	ffs2recov.8

DPADD=	${LIBUFS}
LDADD=	-lufs

WARNS?= 3

.include <bsd.prog.mk>
