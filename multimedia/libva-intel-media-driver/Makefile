PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	21.4.1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a65683be3d3a.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	9783808c766f.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	525dab01c1a2.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	d84559d09c47.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	2b730b48a7aa.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	eb2da1838a51.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	dc18089c0fb4.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	7ff0adca274b.patch:-p1 # https://github.com/intel/media-driver/pull/819
PATCHFILES+=	217287d7ec2f.patch:-p1 # https://github.com/intel/media-driver/pull/819

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
