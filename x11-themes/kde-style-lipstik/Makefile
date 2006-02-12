# New ports collection makefile for:   lipstik
# Date created:                        12th February, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	lipstik
PORTVERSION=	2.2
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/content/files/
PKGNAMEPREFIX=	kde-style-
DISTNAME=	18223-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Modified Plastik KDE style

USE_BZIP2=	yes
USE_KDEBASE_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
