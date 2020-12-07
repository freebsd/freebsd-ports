# Created by: adamw
# $FreeBSD$

PORTNAME=	x265
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265_git/get/${BB_TAG}.tar.gz?meow=/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC:H}/COPYING

USES=		cmake compiler:c++14-lang pathfix dos2unix

BB_TAG=	25b2c07035ff	# Top of the Release_3.4 branch at this time

OPTIONS_DEFINE=		DEBUG OPTIMIZED_FLAGS VMAF
OPTIONS_DEFAULT=	OPTIMIZED_FLAGS HI8P HI10P HI12P
OPTIONS_DEFINE_aarch64=	ASM
OPTIONS_DEFINE_amd64=	ASM SVTHEVC
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM

OPTIONS_MULTI=		PixelWidth
OPTIONS_MULTI_PixelWidth=HI8P HI10P HI12P

DOS2UNIX_FILES=		abrEncApp.cpp
DEBUG_PREVENTS=		OPTIMIZED_FLAGS
DEBUG_PREVENTS_MSG=	Optimizations are incompatible with debugging code
DEBUG_VARS_OFF=		CFLAGS+=-DNDEBUG
DEBUG_CMAKE_ON=		-DCMAKE_ASM_NASM_FLAGS:STRING="-g -O0"
OPTIMIZED_FLAGS_VARS=	CFLAGS+=-O3
SVTHEVC_LIB_DEPENDS=	libSvtHevcEnc.so:multimedia/svt-hevc
SVTHEVC_CMAKE_BOOL=	ENABLE_SVT_HEVC
SVTHEVC_CMAKE_ON=	-DSVT_HEVC_INCLUDE_DIR:PATH="${LOCALBASE}/include/svt-hevc"
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_USES=		localbase:ldflags
VMAF_CMAKE_BOOL=	ENABLE_LIBVMAF
VMAF_CMAKE_ON=	-DVMAF_INCLUDE_DIR:PATH="${LOCALBASE}/include/libvmaf"

DEBUG_DESC=	Enable debugging
HI8P_DESC=	Enable 8-bit pixel-width (you, probably, want this)
HI10P_DESC=	Enable 10-bit pixels (may break on i386)
HI12P_DESC=	Enable 12-bit pixels (may break on i386)
OPTIMIZED_FLAGS_DESC=	Enable O3 optimization
SVTHEVC_DESC=	HEVC encoding via SVT-HEVC
VMAF_DESC=	Per frame and aggregate VMAF score

USE_LDCONFIG=	yes
CMAKE_ARGS=	-DENABLE_TESTS=on -DENABLE_HDR10_PLUS:BOOL=true
LDFLAGS_i386=	-Wl,-znotext
EXTRACT_AFTER_ARGS+=	--exclude compat --strip-components=1
PATCH_WRKSRC=	${WRKSRC:H}
WRKSRC=		${WRKDIR}/source

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 && ${PORT_OPTIONS:MASM}
BUILD_DEPENDS=	as:devel/binutils
USE_GCC=	yes
ASM_PREVENTS=	HI10P HI12P
ASM_PREVENTS_MSG=	Currently HI10P and HI12P doesn't build with assembly
.endif

.if ${ARCH} != aarch64 && ${PORT_OPTIONS:MASM}
BUILD_DEPENDS=	nasm:devel/nasm
.endif

DEFAULT_DEPTH=	${PORT_OPTIONS:MHI*P:O:ts/:T}
OTHER_DEPTHS=	${PORT_OPTIONS:MHI*P:N${DEFAULT_DEPTH}}

.if "${DEFAULT_DEPTH}" == "HI12P"
CMAKE_ARGS+=	-DMAIN12:BOOL=true
.endif

.if "${DEFAULT_DEPTH}" != "HI8P"
CMAKE_ARGS+=	-DHIGH_BIT_DEPTH:BOOL=true
.endif

CMAKE_OTHER_ARGS=${CMAKE_ARGS:C/.*-D_END_CUSTOM_OPTIONS=1 +//W}

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS:=	${CFLAGS:N-O*} -O0 -g
.endif

.for b in ${OTHER_DEPTHS:C/HI([0-9]+)P/\1/}
EXTRA_LINK_FLAGS+=-L${WRKSRC:H}/$bbit

.if ${ARCH} == i386 && $b != 8 || ! ${PORT_OPTIONS:MASM}
ASSEMBLY=false
.else
ASSEMBLY=true
.endif

pre-build::
	@${ECHO_MSG} "---> Building the $b-bit library ---"
	${MKDIR} ${WRKSRC:H}/$bbit
	${CMAKE_BIN} -S ${WRKSRC} -B ${WRKSRC:H}/$bbit \
		${CMAKE_OTHER_ARGS} ${b:C/1./-DHIGH_BIT_DEPTH:BOOL=true/} \
		-DMAIN$b:BOOL=true -DENABLE_ASSEMBLY:BOOL=${ASSEMBLY} \
		-DEXPORT_C_API:BOOL=false -DENABLE_CLI=false
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC:H}/$bbit ${MAKE_ARGS}
	${LN} -f ${WRKSRC:H}/$bbit/libx265.a ${WRKSRC:H}/$bbit/libx265_$bbit.a
	${ECHO_MSG} "---> Built the $b-bit library ---"
.endfor

.if "${EXTRA_LINK_FLAGS}"
CMAKE_ARGS+=	-DEXTRA_LINK_FLAGS:STRING="${EXTRA_LINK_FLAGS}"
CMAKE_ARGS+=	-DEXTRA_LIB="${OTHER_DEPTHS:C/HI([0-9]+)P/x265_\1bit/:C/ /;/gW}"
CMAKE_ARGS+=	${OTHER_DEPTHS:C/HI([0-9]+)P/-DLINKED_\1BIT:BOOL=true/}
.endif

CMAKE_ARGS+=	-DENABLE_SHARED:BOOL=true

.if ${ARCH} == i386 && ${DEFAULT_DEPTH} != "HI8P" || ! ${PORT_OPTIONS:MASM}
CMAKE_ARGS+=	-DENABLE_ASSEMBLY:BOOL=false
.else
CMAKE_ARGS+=	-DENABLE_ASSEMBLY:BOOL=true

do-test:
	${WRKDIR}/.build/test/TestBench
.endif

CMAKE_ARGS+=	-D_END_CUSTOM_OPTIONS=1
CMAKE_ARGS+=	-DENABLE_PIC:BOOL=true

.include <bsd.port.mk>
