# New ports collection makefile for:   colortail
# Date created:                25 February 1999
# Whom:                        Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colortail
PORTVERSION=	0.2.0
CATEGORIES=	misc
MASTER_SITES=	http://people.FreeBSD.org/~cpiazza/distfiles/
# commented out until I upgrade to 0.3.0
# MASTER_SITES=	http://www.student.hk-r.se/~pt98jan/

MAINTAINER=    cpiazza@FreeBSD.org

GNU_CONFIGURE= YES

post-install:
	@ ${MKDIR} ${PREFIX}/share/colortail
	@ ${INSTALL_DATA} ${WRKSRC}/CONFIG ${PREFIX}/share/colortail/CONFIG.example
	@ ${ECHO} "*********************************************"
	@ ${ECHO} "An example of the colour configuration is in"
	@ ${ECHO} "${PREFIX}/share/colortail/CONFIG.example"
	@ ${ECHO} "*********************************************"

.include <bsd.port.mk>
