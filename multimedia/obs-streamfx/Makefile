# $FreeBSD$

PORTNAME=	obs-streamfx
DISTVERSION=	0.9.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Modern effects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	plugin requires a lot of memory for many of the filters to even run, physical or virtual memory can exceed 4GB

BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libobs.so:multimedia/obs-studio

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Xaymar
GH_PROJECT=	obs-StreamFX

CMAKE_ARGS=	-DOBS_STUDIO_DIR=${LOCALBASE}/lib

.include <bsd.port.mk>
