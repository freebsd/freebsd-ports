# New ports collection makefile for:   colortail
# Version required:    0.2.0
# Date created:                25 February 1999
# Whom:                        Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=      colortail-0.2.0
CATEGORIES=    misc
MASTER_SITES=  http://www.student.hk-r.se/~pt98jan/

MAINTAINER=    cpiazza@home.net

GNU_CONFIGURE= YES

post-install:
	@ ${MKDIR} ${PREFIX}/share/colortail
	@ ${INSTALL_DATA} ${WRKSRC}/CONFIG ${PREFIX}/share/colortail/CONFIG.example
	@ ${ECHO} "*********************************************"
	@ ${ECHO} "An example of the colour configuration is in"
	@ ${ECHO} "${PREFIX}/share/colortail/CONFIG.example"
	@ ${ECHO} "*********************************************"

.include <bsd.port.mk>
