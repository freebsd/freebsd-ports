# $FreeBSD$

PORTNAME=	obs-streamfx
DISTVERSION=	0.8.0b2
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Modern effects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Xaymar
GH_PROJECT=	obs-StreamFX

CMAKE_ARGS=	-DOBS_STUDIO_DIR=${LOCALBASE}/lib

.include <bsd.port.mk>
