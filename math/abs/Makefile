# New ports collection makefile for:   abs
# Date created:        20 January 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	abs
PORTVERSION=	0.6
CATEGORIES=	math
MASTER_SITES=	http://www.ping.be/bertin/ \
		http://www.giovannelli.it/~gmarco/files/
DISTNAME=	abs-src-0.6a

MAINTAINER=	gmarco@giovannelli.it

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_XLIB=	yes
WRKSRC=         ${WRKDIR}/abs-src-0.6a/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

post-install:
	@${ECHO} "For the changes from previous version 0.5"
	@${ECHO} "you can read the NEWS file in ${WRKDIR}/abs-src-0.6a"
	@${ECHO} ""
	@${ECHO} "There are also some examples (not installed) in :"
	@${ECHO} "${WRKDIR}/abs-src-0.6a/Examples"
	@${ECHO} ""
	@${ECHO} ""

.include <bsd.port.mk>
