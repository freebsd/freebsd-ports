# $FreeBSD$

PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	20.2.pre3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	2bd42cddbe7c.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	0ef9d7bd97ac.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	b7b1ffbc5323.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	68360a8a07a0.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	c32a4a263b2d.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	79a852a14d7a.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	99a9f233a171.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	0c01a2d56aa2.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	bf8cbb1a04ea.patch:-p1 # https://github.com/intel/media-driver/pull/819

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI driver for Intel HD 5000 (Gen8) or newer

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

BUILD_DEPENDS=	gmmlib>=19.3.1:multimedia/gmmlib \
		libva>=2.7.0:multimedia/libva
LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libigdgmm.so:multimedia/gmmlib \
		libva.so:multimedia/libva

USES=		cmake compiler:c++11-lib localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	intel
ARCH_SUFX=	${ARCH:S/i386/32/:S/amd//:S/x86_//}
CMAKE_OFF=	MEDIA_BUILD_FATAL_WARNINGS BUILD_CMRTLIB
CMAKE_ARGS=	-DBUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
		-DARCH:STRING="${ARCH_SUFX}" \
		-DUFO_MARCH:STRING="${CPUTYPE}"
PLIST_FILES=	lib/dri/iHD_drv_video.so

OPTIONS_DEFINE=	TEST X11
OPTIONS_DEFAULT=X11

# XXX Unbundle googletest
TEST_CMAKE_BOOL=	MEDIA_RUN_TEST_SUITE
TEST_TEST_TARGET=	RunULT

X11_LIB_DEPENDS=	libva-x11.so:multimedia/libva

post-patch:
	@${REINPLACE_CMD} 's/$${GIT_COMMIT}/${DISTVERSIONFULL}/' \
		${WRKSRC}/media_driver/cmake/linux/media_compile_flags_linux.cmake

post-patch-X11-off:
	@${REINPLACE_CMD} -i .nox11 '/find_package.*X11/d' \
		${WRKSRC}/media_driver/media_top_cmake.cmake

.include <bsd.port.mk>
