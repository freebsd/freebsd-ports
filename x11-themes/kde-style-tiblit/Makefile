# New ports collection makefile for:   tiblit
# Date created:                        13th March, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	tiblit
PORTVERSION=	1.2
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde-style-
DISTNAME=	20798-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	KDE style focused on customization

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
