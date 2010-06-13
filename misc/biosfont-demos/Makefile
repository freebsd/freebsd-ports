# New ports collection makefile for:	biosfont-demos
# Date created:				30 June 2006
# Whom:					Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	biosfont-demos
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Demos for the biosfont kernel module

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/include/biosfont.h:${PORTSDIR}/sysutils/biosfont
RUN_DEPENDS=	/boot/modules/biosfont.ko:${PORTSDIR}/sysutils/biosfont

PLIST_FILES=	bin/showchar bin/showdati

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/showchar.c -o ${WRKSRC}/showchar -I${LOCALBASE}/include
	${CC} ${CFLAGS} ${WRKSRC}/showdati.c -o ${WRKSRC}/showdati -I${LOCALBASE}/include -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showchar ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/showdati ${PREFIX}/bin

.include <bsd.port.mk>
