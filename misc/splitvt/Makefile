# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	splitvt
PORTVERSION=	1.6.6
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://slouken.libsdl.org/projects/splitvt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run two shells in a split window/terminal

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

HAS_CONFIGURE=	yes
ALL_TARGET=
MAN1=		splitvt.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not compile: /usr/include/sys/ioctl_compat.h:42:2: Definitions not available without TTY ioctl compat
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's|" -O"|"${CFLAGS}"|g ; \
		 s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
