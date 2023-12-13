PORTNAME=	obs-streamfx
DISTVERSION=	0.12.0b299
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Modern effects
WWW=		https://github.com/Xaymar/obs-StreamFX

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	plugin requires a lot of memory for many of the filters to even run, physical or virtual memory can exceed 4GB

BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libobs.so:multimedia/obs-studio

USES=		cmake gl localbase:ldflags qt:6 # localbase:ldflags is related to https://github.com/Xaymar/obs-StreamFX/issues/828
USE_QT=		base tools:build
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	Xaymar
GH_PROJECT=	obs-StreamFX

GH_TUPLE=	nlohmann:json:db78ac1d7716f56fc9f1b030b715f872f93964e4:nlohmann_json/third-party/nlohmann-json \
		Xaymar:msvc-redist-helper:aa4665ccf68a382f1c2b115fb6c9668b6a8bd64d:Xaymar_msvc_redist_helper/third-party/msvc-redist-helper \
		NVIDIA:MAXINE-AR-SDK:ca10ac3:NVIDIA_MAXINE_AR_SDK/third-party/nvidia-maxine-ar-sdk \
		NVIDIA:MAXINE-VFX-SDK:f63d9d1:NVIDIA_MAXINE_VFX_SDK/third-party/nvidia-maxine-vfx-sdk \
		Xaymar:cmake-clang:f249747:Xaymar_cmake_clang/cmake/clang \
		Xaymar:cmake-version:16bfa95:Xaymar_cmake_version/cmake/version

CMAKE_ARGS=	-DOBS_STUDIO_DIR=${LOCALBASE}/lib
CMAKE_ON=	STRUCTURE_PACKAGEMANAGER
CXXFLAGS+=	-I${LOCALBASE}/include/obs # workaround for https://github.com/Xaymar/obs-StreamFX/issues/828

.include <bsd.port.mk>
