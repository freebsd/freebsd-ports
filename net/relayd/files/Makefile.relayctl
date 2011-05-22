# $FreeBSD$

PROG=	relayctl

.PATH:	${.CURDIR}/../../lib/libutil
SRCS=	imsg-buffer.c \
	imsg.c

.PATH:	${.CURDIR}/../relayd
SRCS+=	log.c

.PATH:	${.CURDIR}
SRCS+=	relayctl.c \
	parser.c

MAN=	relayctl.8

CFLAGS+=	-D__dead=''
CFLAGS+=	-I${.CURDIR} \
		-I${.CURDIR}/../../lib/libutil \
		-I${.CURDIR}/../relayd \
		-I${PREFIX}/include

.include <bsd.prog.mk>
