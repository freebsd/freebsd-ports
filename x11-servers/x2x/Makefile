# New ports collection makefile for:	x2x
# Date created:		3 September 2000
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	x2x
PORTVERSION=	1.27
PORTREVISION=	3
CATEGORIES=	x11-servers
MASTER_SITES=	http://gatekeeper.dec.com/pub/DEC/SRC/x2x/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to link multiple X servers together

USE_IMAKE=	yes
USE_XORG=	x11 xext xtst
USE_GMAKE=	yes
MAKE_ENV=	MAKE=${GMAKE}
MAN1=		x2x.1
PLIST_FILES=	bin/x2x

.include <bsd.port.mk>
