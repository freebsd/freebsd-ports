# New ports collection makefile for:	boclient
# Version required:	1.21
# Date created:		12 August 1998
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

DISTNAME=	bo121unix
PKGNAME=	boclient-1.21
CATEGORIES=	net security
MASTER_SITES=	http://www.ennui.net/~crioux/ \
		http://orifice.rotten.com/cDc/ \
		http://www.cultdeadcow.com/tools/

MAINTAINER=	darius@dons.net.au

WRKSRC=		${WRKDIR}/bo
GNU_CONFIGURE=	yes

post-install:
		strip ${PREFIX}/bin/bounix

.include <bsd.port.mk>
