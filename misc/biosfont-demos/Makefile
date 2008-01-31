# New ports collection makefile for:	biosfont-demos
# Date created:				30 June 2006
# Whom:					Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	biosfont-demos
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Demos for the biosfont kernel module

BUILD_DEPENDS=	${LOCALBASE}/include/biosfont.h:${PORTSDIR}/sysutils/biosfont
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	bin/showchar bin/showdati

do-build:
	${CC} ${WRKSRC}/showchar.c -o ${WRKSRC}/showchar -I${LOCALBASE}/include
	${CC} ${WRKSRC}/showdati.c -o ${WRKSRC}/showdati -I${LOCALBASE}/include -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showchar ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/showdati ${PREFIX}/bin

.include <bsd.port.mk>
