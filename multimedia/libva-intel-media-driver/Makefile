PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	22.4.2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	dc74b5f2fe82.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	921023462274.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	6de6d1940e88.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	8f3fa352bd79.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	2c68fd4a62fb.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	e850bcb7b6e1.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	22d91bd65702.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	d7f88bd305f8.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	d7280f526022.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	231c06faa4c4.patch:-p1 # https://github.com/intel/media-driver/pull/819

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
