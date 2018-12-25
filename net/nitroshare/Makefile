# $FreeBSD$

PORTNAME=	nitroshare
DISTVERSION=	0.3.4-642
DISTVERSIONSUFFIX=	-g2046ccb
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network file transfer application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libqhttpengine.so:www/qhttpengine \
		libqmdnsengine.so:dns/qmdnsengine

USES=		cmake qt:5
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-desktop
USE_QT=		core gui network widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
