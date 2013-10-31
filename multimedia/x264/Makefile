# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x264
PORTVERSION=	0.${X264_BUILD}.${X264_REV}
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/x264/snapshots/ \
		http://samples.mplayerhq.hu/yuv4mpeg2/:pgo
DISTNAME=	${PORTNAME}-snapshot-${X264_SNAPSHOT}-2245-stable
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	x264
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Library and tool for encoding H.264/AVC video streams

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm>=0.6.0:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

X264_BUILD=	136
X264_REV=	2358
X264_COMMIT=	3361d59a0a83dcb8b321cc0eb8e6ba68ca49c7d4
X264_GITVER=	${X264_COMMIT:C/^(.......).*$/\1/g}
X264_SNAPSHOT=	20130827

USES=		gmake
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		ASM DEBUG PGO GCC GPAC X11_OUTPUT
OPTIONS_DEFAULT=	ASM GPAC
ASM_DESC=		Enable Assembly Optimizations
GCC_DESC=		Use current GCC
GPAC_DESC=		Enable MPEG-4 Output
X11_OUTPUT_DESC=	Enable X11 Output

CONFIGURE_ARGS+=	--extra-cflags="-I${LOCALBASE}/include" \
			--extra-ldflags="-L${LOCALBASE}/lib" \
			--enable-static --enable-shared \
			--disable-opencl

PLIST_SUB+=	X264_BUILD=${X264_BUILD}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCC}
USE_GCC=	yes
.elif ${PORT_OPTIONS:MPGO}
USE_GCC=	any
.endif

.if !${PORT_OPTIONS:MASM}
CONFIGURE_ARGS+=	--disable-asm
.endif

.if ${PORT_OPTIONS:MDEBUG} || defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

.if ${PORT_OPTIONS:MPGO}
# y4m sample video
Y4M_VIDEO=example.y4m
Y4M_VIDEO_DISTFILE=example.y4m.bz2

DISTFILES+=	${Y4M_VIDEO_DISTFILE}:pgo
ALL_TARGET=	fprofiled
MAKE_ENV+=	VIDS="${WRKDIR}/${Y4M_VIDEO}"

RESTRICTED=	${Y4M_VIDEO_DISTFILE} file may not be mirrored
RESTRICTED_FILES=	${Y4M_VIDEO_DISTFILE}
.endif

.if ${PORT_OPTIONS:MGPAC}
LIB_DEPENDS+=		libgpac.so:${PORTSDIR}/multimedia/gpac-libgpac
.else
CONFIGURE_ARGS+=	--disable-gpac
.endif

.if ${PORT_OPTIONS:MX11_OUTPUT}
CONFIGURE_ARGS+=	--enable-visualize
USE_XORG=		x11
.endif

post-extract:
.if ${PORT_OPTIONS:MPGO}
	@( cd ${WRKDIR} && ${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${Y4M_VIDEO_DISTFILE} > ${Y4M_VIDEO} )
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|/bin/bash|${LOCALBASE}/bin/bash|; \
		s|gpac_static|gpac|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/version.sh
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
