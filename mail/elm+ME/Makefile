# New ports collection makefile for:    elm
# Version required:     2.4 ME8b
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.7 1995/10/20 07:35:26 asami Exp $
#

DISTNAME=       elm-2.4pl24me8
PKGNAME=        elm-2.4m8b
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
