PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	21.4.3
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	3dd1e4e27b5d.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	e5ec4a59db29.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	1915e449aa7e.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	9b6b795ee0a1.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	4acc8c8f871c.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	e9ff848336f6.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	520dcffa2cb6.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	54e6627346a4.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	57bc24a4a61c.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	690e692143a0.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	42ffd7983a32.patch:-p1 # gmmlib 22.0

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI driver for Intel HD 5000 (Gen8) or newer

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

BUILD_DEPENDS=	gmmlib>=19.3.1:multimedia/gmmlib \
		libva>=2.7.0:multimedia/libva
LIB_DEPENDS=	libigdgmm.so:multimedia/gmmlib \
		libva.so:multimedia/libva

USES=		cmake:testing compiler:c++11-lib localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	intel
ARCH_SUFX=	${ARCH:S/i386/32/:S/amd//:S/x86_//}
CMAKE_OFF=	MEDIA_BUILD_FATAL_WARNINGS BUILD_CMRTLIB
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	MEDIA_RUN_TEST_SUITE # XXX Unbundle googletest
CMAKE_TESTING_TARGET=	RunULT
CMAKE_ARGS=	-DBUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
		-DARCH:STRING="${ARCH_SUFX}" \
		-DUFO_MARCH:STRING="${CPUTYPE}"
PLIST_FILES=	lib/dri/iHD_drv_video.so

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_LIB_DEPENDS=	libva-x11.so:multimedia/libva

post-patch:
	@${REINPLACE_CMD} 's/$${GIT_COMMIT}/${DISTVERSIONFULL}/' \
		${WRKSRC}/media_driver/cmake/linux/media_compile_flags_linux.cmake

post-patch-X11-off:
	@${REINPLACE_CMD} -i .nox11 '/find_package.*X11/d' \
		${WRKSRC}/media_driver/media_top_cmake.cmake

.include <bsd.port.mk>
