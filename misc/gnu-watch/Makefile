# New ports collection makefile for:	gnu-watch
# Date created:				3 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	watch
DISTVERSION=	3.2.5
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/
PKGNAMEPREFIX=	gnu-
DISTNAME=	procps-${DISTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	GNU watch command

USE_GETOPT_LONG=yes
USE_GCC=	3.4+

MAN1=		gnu-watch.1

PLIST_FILES=	bin/${UNIQUENAME}

CFLAGS+=	-fno-common -ffast-math -D_GNU_SOURCE -O2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${PATCH} -s ${WRKSRC}/watch.c ${FILESDIR}/watch.c.patch
.endif

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -s -c ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${UNIQUENAME}.o
	${CC} ${CFLAGS} ${LDFLAGS} -s -lncurses ${WRKSRC}/${UNIQUENAME}.o -o ${WRKSRC}/${UNIQUENAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${UNIQUENAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/watch.1 ${MANPREFIX}/man/man1/gnu-watch.1

.include <bsd.port.post.mk>
