# New ports collection makefile for:   	centericq
# Version required:                    	2.0.0
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	center-2.0.0
CATEGORIES=	net
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	cpiazza@FreeBSD.org

WRKSRC=		${WRKDIR}/center
USE_GMAKE=	yes
USE_NEWGCC=	yes

post-patch:
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:' ${WRKSRC}/centerICQ.cc

pre-build:
	@(cd ${WRKDIR}/ktools/src; ${SETENV} CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ${GMAKE} ${MAKE_ARGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/center ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/center
	${INSTALL_DATA} ${WRKSRC}/sound/* ${PREFIX}/share/center

.include <bsd.port.mk>
