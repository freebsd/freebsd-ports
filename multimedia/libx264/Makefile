# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#
# Updating notes: see multimedia/x264/Makefile.

PORTNAME=	libx264
PORTVERSION=	0.${X264_BUILD}.${X264_REV}
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/x264/snapshots/ \
		http://samples.mplayerhq.hu/yuv4mpeg2/:pgo
DISTNAME=	x264-snapshot-${X264_SNAPSHOT}-2245-stable
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	x264
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Library for encoding H.264/MPEG-4 AVC video

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm>=1.2.0:${PORTSDIR}/devel/yasm \
		bash:${PORTSDIR}/shells/bash

X264_BUILD=	142
X264_REV=	2455
X264_COMMIT=	021c0dc6c95c1bc239c9db78a80dd85fc856a4dd
X264_GITVER=	${X264_COMMIT:C/^(.......).*$/\1/g}
X264_SNAPSHOT=	20140827

USES=		gmake pathfix tar:bzip2
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		ASM DEBUG GCC HI10P PGO
OPTIONS_DEFAULT=	ASM

ASM_DESC=	Enable Assembly Optimizations
DEBUG_DESC=	Generate Debugging Symbols
GCC_DESC=	Use current GCC
HI10P_DESC=	Enable High 10 Profile 10-bit encoding

ASM_CONFIGURE_OFF=	--disable-asm
DEBUG_CONFIGURE_ON=	--enable-debug
HI10P_CONFIGURE_ON=	--bit-depth=10
CONFIGURE_ARGS+=	--extra-cflags="-I${LOCALBASE}/include" \
			--extra-ldflags="-L${LOCALBASE}/lib" \
			--enable-static --enable-shared \
			--disable-opencl

CFLAGS_armv6+=		-mcpu=arm1136jf-s

PATHFIX_MAKEFILEIN=	Makefile
PLIST_SUB+=		X264_BUILD=${X264_BUILD}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCC}
USE_GCC=	yes
.elif ${PORT_OPTIONS:MPGO}
USE_GCC=	any
.endif

.if ${PORT_OPTIONS:MPGO}
# y4m sample video
Y4M_VIDEO=		example.y4m
Y4M_VIDEO_DISTFILE=	example.y4m.bz2

DISTFILES+=	${Y4M_VIDEO_DISTFILE}:pgo
ALL_TARGET=	fprofiled
MAKE_ENV+=	VIDS="${WRKDIR}/${Y4M_VIDEO}"

RESTRICTED=		${Y4M_VIDEO_DISTFILE} file may not be mirrored
RESTRICTED_FILES=	${Y4M_VIDEO_DISTFILE}
.endif

post-extract:
.if ${PORT_OPTIONS:MPGO}
	@( cd ${WRKDIR} && ${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${Y4M_VIDEO_DISTFILE} > ${Y4M_VIDEO} )
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|/bin/bash|${LOCALBASE}/bin/bash|; \
		s|gpac_static|gpac|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|bash|sh|; \
		s|VER="x"|VER="${X264_REV} ${X264_GITVER}"|; \
		s|VERSION=""|VERSION=" r${X264_REV} ${X264_GITVER}"|' \
		${WRKSRC}/version.sh

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/x264
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libx264.so.*

.include <bsd.port.mk>
