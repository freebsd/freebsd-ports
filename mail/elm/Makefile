# New ports collection makefile for:    elm
# Version required:     2.4 ME8b
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1995/11/19 21:11:30 ache Exp $
#

DISTNAME=       elm-2.4pl24me8
VERSION=        2.4m8b          # allows to not edit elm+* Makefiles
PKGNAME=        elm-${VERSION}
PATCHFILES=     elm-2.4pl24me8a.diffs.Z elm-2.4pl24me8b.diffs.Z
PATCH_DIST_STRIP= -p1
CATEGORIES+=	mail
MASTER_SITES=   ftp://cs.hmc.edu/pub/me/
PATCH_SITES=    ${MASTER_SITES}

MAINTAINER=	ache@FreeBSD.ORG

pre-patch:
	rm -f ${WRKSRC}/src/state.c

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install

.include <bsd.port.mk>
