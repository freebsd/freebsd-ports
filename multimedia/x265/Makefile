PORTNAME=	x265
PORTVERSION=	4.3
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/Multicorewareinc/x265/releases/download/${PORTVERSION}/ \
		http://ftp.videolan.org/pub/videolan/x265/
DISTNAME=	${PORTNAME}_${PORTVERSION}

PATCH_SITES=	https://github.com/Multicorewareinc/x265/commit/
PATCHFILES=	fbd43389ed39b8623bdf081fae3020d96052d962.patch:-p1 \
		9ddc216defd1fa85535cb91456a9f6c09a2c3abc.patch:-p1 \
		ff33e3e2ce1af2ceee94958c7273e3b1d083d5e5.patch:-p1 \
		62728cd0c696655f34972b47cff1e1e77d84e426.patch:-p1 \
		d0418793c134fe943098f5f0700ae87fcd4c8557.patch:-p1 \
		98eec4057fc20850b59ed292b3f13ddeefc2f93f.patch:-p1 \
		f0179ac2ea69d349de0b20848d0431971d8db3b9.patch:-p1 \
		ae31887b575154ca64164153b9802a92cacd9387.patch:-p1 \
		93b4b94f8d4ac1808e715766b180932948e671a6.patch:-p1 \
		e761edf5ecd1260237766bb7b7b2583e933d5ffb.patch:-p1 \
		a0468d239fbfa659641ce6085aa9b63977a5785d.patch:-p1 \
		ea8b761899ecf91cbd4f8b83e85d8444b1b94c80.patch:-p1 \
		688efad6e96d755188cb08fbe9e16822e1cfa3f1.patch:-p1 \
		d978725394991e13a07a8002e0ff8b7d01eea08a.patch:-p1

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
.endif

.if ${ARCH} == i386
CMAKE_ARGS+=	-DENABLE_ASSEMBLY:BOOL=false
.endif

# ENABLE_LIBVMAF changes the layout of x265_api, so the libraries for
# the other depths must agree with the main one about it.
CMAKE_OTHER_ARGS=	${CMAKE_ARGS:M*VMAF*} \
			${CMAKE_ARGS:C/.*-D_END_CUSTOM_OPTIONS=1 +//W}

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

.if !empty(PATCHFILES)
# Make the version string count the upstream commits applied on top of
# the release, and name the most recent of them.
post-patch:
	${REINPLACE_CMD} -E \
	    -e 's/^(releasetagdistance: ).*/\1${PATCHFILES:[#]}/' \
	    -e 's/^(repositorychangeset: ).*/\1${PATCHFILES:[-1]:C/^(.......).*/\1/}/' \
	    ${WRKSRC:H}/x265Version.txt
.endif

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
