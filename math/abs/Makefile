# New ports collection makefile for:   abs
# Date created:        20 January 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	abs
PORTVERSION=	0.6a
CATEGORIES=	math
MASTER_SITES=	http://www.ping.be/bertin/ \
		http://www.giovannelli.it/~gmarco/files/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	gmarco@giovannelli.it

USE_XLIB=	yes
USE_XPM=	yes
WRKSRC=         ${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

post-install:
	@${ECHO} "For the changes from previous version 0.5"
	@${ECHO} "you can read the NEWS file in ${WRKDIR}"
	@${ECHO} ""
	@${ECHO} "There are also some examples (not installed) in :"
	@${ECHO} "${WRKDIR}/Examples"
	@${ECHO} ""
	@${ECHO} ""

.include <bsd.port.mk>
