PORTNAME=	obs-streamfx
DISTVERSION=	0.11.1
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

USES=		cmake localbase:ldflags qt:5 # localbase:ldflags is related to https://github.com/Xaymar/obs-StreamFX/issues/828
USE_QT=		core gui widgets buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	Xaymar
GH_PROJECT=	obs-StreamFX

GH_TUPLE=	Xaymar:cmake-clang:f249747ff0a460b3e564801079445a2216b7c068:Xaymar_cmake_clang/cmake/clang \
		Xaymar:cmake-codesign:d02ee94cb9c47ef6f8d2e9a5d67473b7e5cfc5bf:Xaymar_cmake_codesign/cmake/codesign \
		nlohmann:json:db78ac1d7716f56fc9f1b030b715f872f93964e4:nlohmann_json/third-party/nlohmann-json \
		Xaymar:msvc-redist-helper:aa4665ccf68a382f1c2b115fb6c9668b6a8bd64d:Xaymar_msvc_redist_helper/third-party/msvc-redist-helper \
		NVIDIA:MAXINE-AR-SDK:3bd2be62a4b309d56e270bbf05a622395ce95f04:NVIDIA_MAXINE_AR_SDK/third-party/nvidia-maxine-ar-sdk \
		NVIDIA:MAXINE-VFX-SDK:7f69da2ee4dcb02e6b024b3f40c5892de84fcb45:NVIDIA_MAXINE_VFX_SDK/third-party/nvidia-maxine-vfx-sdk \
		Xaymar:cmake-clang:18ba565ff80cb5e6103a93e88a0265545c004707:Xaymar_cmake_clang/third-party/msvc-redist-helper/cmake/clang

CMAKE_ARGS=	-DOBS_STUDIO_DIR=${LOCALBASE}/lib
CMAKE_ON=	STRUCTURE_PACKAGEMANAGER
CXXFLAGS+=	-I${LOCALBASE}/include/obs # workaround for https://github.com/Xaymar/obs-StreamFX/issues/828

.include <bsd.port.mk>
