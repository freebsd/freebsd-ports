# $FreeBSD$

PORTNAME=	obs-ndi
DISTVERSION=	4.9.1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Network Device Interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake compiler:c++11-lang localbase:ldflags qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Palakis
USE_QT=		core gui widgets buildtools_build qmake_build

.include <bsd.port.mk>
