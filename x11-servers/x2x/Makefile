# New ports collection makefile for:	x2x
# Date created:		3 September 2000
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	x2x
PORTVERSION= 	1.27
CATEGORIES=	x11
MASTER_SITES=	http://gatekeeper.dec.com/pub/DEC/SRC/x2x/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org

USE_IMAKE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	MAKE=${GMAKE}
MANCOMPRESSED=	yes
MAN1=		x2x.1

do-install:
	cd ${WRKSRC}; make install; make install.man

.include <bsd.port.mk>
