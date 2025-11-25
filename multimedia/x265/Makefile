PORTNAME=	x265
PORTVERSION=	4.1
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265_git/downloads/ \
		http://ftp.videolan.org/pub/videolan/x265/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format
WWW=		https://www.x265.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC:H}/COPYING

USES=		cmake compiler:c++14-lang cpe pathfix dos2unix
CPE_VENDOR=	multicorewareinc
DOS2UNIX_FILES=	common/scaler.cpp
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DENABLE_TESTS=on -DGIT_ARCHETYPE=1
CMAKE_ON=	ENABLE_HDR10_PLUS
LDFLAGS_i386=	-Wl,-znotext
EXTRACT_AFTER_ARGS+=	--exclude compat --exclude md5\.* --strip-components=1
PATCH_WRKSRC=	${WRKSRC:H}
WRKSRC=		${WRKDIR}/source
BB_TAG=		Release_${DISTVERSION}

OPTIONS_DEFINE=			VMAF
OPTIONS_DEFINE_amd64=		SVTHEVC
OPTIONS_DEFINE_powerpc64=	ALTIVEC
OPTIONS_DEFINE_powerpc64le=	${OPTIONS_DEFINE_powerpc64}
OPTIONS_DEFAULT=		HI10P HI12P HI8P OPTIMIZED_FLAGS
OPTIONS_DEFAULT_powerpc64le=	ALTIVEC

OPTIONS_MULTI=			PIXELWIDTH
OPTIONS_MULTI_PIXELWIDTH=	HI10P HI12P HI8P
OPTIONS_RADIO=			OPTIMIZATION
OPTIONS_RADIO_OPTIMIZATION=	DEBUG OPTIMIZED_FLAGS

DEBUG_DESC=		Enable debugging (and -O0 -g)
HI10P_DESC=		Enable 10-bit pixels (may break on i386)
HI12P_DESC=		Enable 12-bit pixels (may break on i386)
HI8P_DESC=		Enable 8-bit pixel-width (you, probably, want this)
OPTIMIZED_FLAGS_DESC=	Enable O3 optimization
SVTHEVC_DESC=		HEVC encoding via SVT-HEVC
VMAF_DESC=		VMAF scores
VMAF_USES=		localbase:ldflags

DEBUG_CMAKE_ON=		-DCMAKE_ASM_NASM_FLAGS:STRING="-g -O0"
SVTHEVC_LIB_DEPENDS=	libSvtHevcEnc.so:multimedia/svt-hevc
SVTHEVC_CMAKE_ON=	-DSVT_HEVC_INCLUDE_DIR:PATH="${LOCALBASE}/include/svt-hevc"
SVTHEVC_CMAKE_BOOL=	ENABLE_SVT_HEVC
VMAF_CMAKE_ON=		-DVMAF_INCLUDE_DIR:PATH="${LOCALBASE}/include/libvmaf"
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_CMAKE_BOOL=	ENABLE_LIBVMAF

.include <bsd.port.options.mk>

.if ${ARCH} == i386 && ${PORT_OPTIONS:MHI8P} || ${ARCH} == amd64
BUILD_DEPENDS=	nasm:devel/nasm
.endif

DEFAULT_DEPTH=	${PORT_OPTIONS:MHI*P:O:ts/:T}
OTHER_DEPTHS=	${PORT_OPTIONS:MHI*P:N${DEFAULT_DEPTH}}

.if "${DEFAULT_DEPTH}" == "HI12P"
CMAKE_ARGS+=	-DMAIN12:BOOL=true
.endif

.if "${DEFAULT_DEPTH}" != "HI8P"
CMAKE_ARGS+=	-DHIGH_BIT_DEPTH:BOOL=true
.if ${ARCH} == i386
CMAKE_ARGS+=	-DENABLE_ASSEMBLY:BOOL=false
.endif
.endif

CMAKE_OTHER_ARGS=	${CMAKE_ARGS:C/.*-D_END_CUSTOM_OPTIONS=1 +//W}

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS:=	${CFLAGS:N-O*} -O0 -g
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_FLAGS}
CFLAGS:=	${CFLAGS:N-O*} -O3
.endif

.if ${ARCH} == armv7
CMAKE_ARGS+=	-DENABLE_NEON:BOOL=true
.endif

.if ${PORT_OPTIONS:MALTIVEC}
CMAKE_ARGS+=		-DENABLE_ALTIVEC=true \
			-DCPU_POWER8=true
.else
CMAKE_ARGS+=		-DENABLE_ALTIVEC=false \
			-DCPU_POWER8=false
.endif

.for b in ${OTHER_DEPTHS:C/HI([0-9]+)P/\1/}
EXTRA_LINK_FLAGS+=	-L${WRKSRC:H}/$bbit

.if (${ARCH} == i386 || ${ARCH:Mpowerpc64*}) && $b != 8
ASSEMBLY=	false
.else
ASSEMBLY=	true
.endif

pre-build::
	@${ECHO_MSG} "---> Building the $b-bit library ---"
	${MKDIR} ${WRKSRC:H}/$bbit
	${CMAKE_BIN} -S ${WRKSRC} -B ${WRKSRC:H}/$bbit \
		${CMAKE_OTHER_ARGS} ${b:C/1./-DHIGH_BIT_DEPTH:BOOL=true/} \
		-DMAIN$b:BOOL=true -DENABLE_ASSEMBLY:BOOL=${ASSEMBLY} \
		-DENABLE_ALTIVEC:BOOL=${ASSEMBLY} \
		-DCPU_POWER8:BOOL=${ASSEMBLY} -DEXPORT_C_API:BOOL=false \
		-DENABLE_CLI=false
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC:H}/$bbit ${MAKE_ARGS}
	${LN} -f ${WRKSRC:H}/$bbit/libx265.a ${WRKSRC:H}/$bbit/libx265_$bbit.a
	@${ECHO_MSG} "---> Built the $b-bit library ---"
.endfor

.if "${EXTRA_LINK_FLAGS}"
CMAKE_ARGS+=	-DEXTRA_LINK_FLAGS:STRING="${EXTRA_LINK_FLAGS}"
CMAKE_ARGS+=	-DEXTRA_LIB="${OTHER_DEPTHS:C/HI([0-9]+)P/x265_\1bit/:C/ /;/gW}"
CMAKE_ARGS+=	${OTHER_DEPTHS:C/HI([0-9]+)P/-DLINKED_\1BIT:BOOL=true/}
.endif

CMAKE_ARGS+=	-DENABLE_SHARED:BOOL=true

do-test:
.if ${PORT_OPTIONS:MHI8P} || ${ARCH} != i386
	${WRKDIR}/.build/test/TestBench
.else
	@${ECHO_MSG} On ${ARCH} TestBench is only built, when 8bit is enabled
.endif

CMAKE_ARGS+=	-D_END_CUSTOM_OPTIONS=1
CMAKE_ARGS+=	-DENABLE_PIC:BOOL=true

.if !defined(DEVELOPER)
CMAKE_ARGS+=	-Wno-dev
.endif

.include <bsd.port.mk>
