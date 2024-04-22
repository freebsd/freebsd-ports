PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	23.4.3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	d54347296.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	7e26e598e.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	6e1f5e635.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	7485cf796.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	3297302d8.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	0f3012331.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	695b56fe0.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	be6bd904b.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	daaa7172e.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	59c560101.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	2933bb51e.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	4ec9b2bd6.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	17d384458.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	abb792cad.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	7d261abf2.patch:-p1 #https://github.com/intel/media-driver/pull/1785
PATCHFILES+=	67961a267.patch:-p1 #https://github.com/intel/media-driver/pull/1785

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VAAPI driver for Intel HD 5000 (Gen8) or newer
WWW=		https://01.org/intel-media-for-linux

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
