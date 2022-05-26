PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	22.4.3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	3ee693b2bad3.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	a4313cae8533.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	4980335d82c4.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	fcfc4431f4b7.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	77382f10e352.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	4440a982d235.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	8249202403a4.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	ab1209a220eb.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	acf5314930d3.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	9acd334c50a7.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	a338a45f0675.patch:-p1 # https://github.com/intel/media-driver/pull/819

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
