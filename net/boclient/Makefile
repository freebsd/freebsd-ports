# New ports collection makefile for:	boclient
# Date created:		12 August 1998
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	boclient
PORTVERSION=	1.21
CATEGORIES=	net security
MASTER_SITES=	http://www2.ennui.net/~crioux/ \
		http://orifice.rotten.com/cDc/
DISTNAME=	bo121unix

MAINTAINER=	darius@dons.net.au
COMMENT=	Client program for the Back Orifice Windows program

PLIST_FILES=	bin/bounix
WRKSRC=		${WRKDIR}/bo
GNU_CONFIGURE=	yes

post-install:
		${STRIP_CMD} ${PREFIX}/bin/bounix

.include <bsd.port.mk>
