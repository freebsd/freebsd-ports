# $FreeBSD$

PORTNAME=	media-driver
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	18.3.0
PORTREVISION=	3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	libva-intel-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Intel Media Driver for VAAPI

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libigdgmm.so:multimedia/gmmlib \
		libva.so:multimedia/libva

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	intel
ARCH_SUFX=	${ARCH:S/i386/32/:S/amd//:S/x86_//}
CMAKE_OFF=	MEDIA_BUILD_FATAL_WARNINGS INSTALL_DRIVER_SYSCONF
CMAKE_ARGS=	-DBUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
		-DARCH:STRING="${ARCH_SUFX}" \
		-DUFO_MARCH:STRING="${CPUTYPE}"
PLIST_FILES=	lib/dri/iHD_drv_video.so \
		lib/igfxcmrt${ARCH_SUFX}.so

OPTIONS_DEFINE=	TEST

# XXX Unbundle googletest
TEST_CMAKE_BOOL=	MEDIA_RUN_TEST_SUITE
TEST_TEST_TARGET=	RunULT

post-patch:
	@${REINPLACE_CMD} -e '/install.*igfxcmrt/s/64/${ARCH_SUFX}/' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/-D__linux__/d' \
		${WRKSRC}/media_driver/cmake/linux/media_compile_flags_linux.cmake
# Silence -Wmacro-redefined
	@${REINPLACE_CMD} -e '/__fastcall/d' \
		${WRKSRC}/media_driver/linux/common/cm/cm_mem_os.h

.include <bsd.port.mk>
