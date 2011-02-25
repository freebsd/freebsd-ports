# New ports collection makefile for:   knifty
# Date created:                        22nd February, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	knifty
PORTVERSION=	0.4.2
PORTREVISION=	10
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde-windeco-
DISTNAME=	8841-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Lightweight KDE window decoration

USE_BZIP2=	yes
USE_KDEBASE_VER=3
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
USE_AUTOTOOLS=	libtool
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
