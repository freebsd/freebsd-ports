# $FreeBSD$

PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	19.4.0
PORTREVISION=	4
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c203c89a9695.patch:-p1 12b7fcded6c7.patch:-p1
PATCHFILES+=	12a0cac7047b.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	83338cf44f05.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	2e1b34f259d6.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	c15003c2c732.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	b83b1334f869.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	5dffdeded8bc.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	04890b2f9a59.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	b585f7586dde.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	38d37bff5a68.patch:-p1 # https://github.com/intel/media-driver/pull/819

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI driver for Intel HD 5000 (Gen8) or newer

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

BUILD_DEPENDS=	gmmlib>=19.3.1:multimedia/gmmlib \
		libva>=2.6.0:multimedia/libva
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

post-patch-X11-off:
	@${REINPLACE_CMD} -i .nox11 '/find_package.*X11/d' \
		${WRKSRC}/media_driver/media_top_cmake.cmake

.include <bsd.port.mk>
