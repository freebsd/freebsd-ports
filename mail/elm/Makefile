# New ports collection makefile for:    elm
# Version required:     2.4 ME8a
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1995/09/22 20:10:54 ache Exp $
#

DISTNAME=       elm-2.4pl24me8
PKGNAME=        elm-2.4m8a
PATCHFILES=     elm-2.4pl24me8a.diffs.Z
PATCH_DIST_STRIP= -p1
CATEGORIES+=	mail
MASTER_SITES=   ftp://cs.hmc.edu/pub/me/
PATCH_SITES=    ${MASTER_SITES}

MAINTAINER=	ache@FreeBSD.ORG

IS_INTERACTIVE=	yes
NO_PACKAGE=     yes     # I don't know, why

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install

.include <bsd.port.mk>
