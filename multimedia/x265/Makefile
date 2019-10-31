# Created by: adamw
# $FreeBSD$

PORTNAME=	x265
PORTVERSION=	3.2.1
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/downloads/ \
		https://downloads.videolan.org/pub/videolan/x265/ \
		https://mirror.leaseweb.com/videolan/x265/ \
		http://downloads.videolan.org/pub/videolan/x265/ \
		http://mirror.leaseweb.com/videolan/x265/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC:H}/COPYING

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake compiler:c++14-lang pathfix

OPTIONS_DEFINE=		DEBUG OPTIMIZED_FLAGS VMAF
OPTIONS_DEFINE_amd64=	HI10P HI12P SVTHEVC

DEBUG_PREVENTS=		OPTIMIZED_FLAGS
DEBUG_PREVENTS_MSG=	Optimizations are incompatible with debugging code
DEBUG_VARS_OFF=		CFLAGS+=-DNDEBUG CPPFLAGS+=-DNDEBUG 
HI10P_CMAKE_BOOL=	HIGH_BIT_DEPTH
HI12P_CMAKE_BOOL=	MAIN12
HI12P_IMPLIES=		HI10P
OPTIMIZED_FLAGS_VARS=	CFLAGS+=-O3 CXXFLAGS+=-O3
SVTHEVC_LIB_DEPENDS=	libSvtHevcEnc.so:multimedia/svt-hevc
SVTHEVC_CMAKE_BOOL=	ENABLE_SVT_HEVC
SVTHEVC_CMAKE_ON=	-DSVT_HEVC_INCLUDE_DIR:PATH="${LOCALBASE}/include/svt-hevc"
VMAF_BUILD_DEPENDS=	${LOCALBASE}/lib/libvmaf.a:multimedia/vmaf
VMAF_USES=		localbase:ldflags
VMAF_CMAKE_BOOL=	ENABLE_LIBVMAF

DEBUG_DESC=	Enable debugging
HI10P_DESC=	Enable HI10P Support (64-bit only)
HI12P_DESC=	Enable HI12P Support (64-bit only)
OPTIMIZED_FLAGS_DESC=	Enable O3 optimization
SVTHEVC_DESC=	HEVC encoding via SVT-HEVC
VMAF_DESC=	Per frame and aggregate VMAF score

USE_LDCONFIG=	yes
CMAKE_ARGS=	-DENABLE_PIC=on -DENABLE_TESTS=on
LDFLAGS_i386=	-Wl,-znotext
EXTRACT_AFTER_ARGS+=	--exclude compat
PATCH_WRKSRC=	${WRKSRC:H}
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}/source

do-test:
	${WRKSRC}/test/TestBench

.include <bsd.port.mk>
