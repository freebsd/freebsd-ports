# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#
# NOTES FOR UPDATING PORT:
#
# We use tarballs from the *stable* branch of the upstream git repository.
#
# X264_BUILD is the "core" number, and can be found in x264.h.
#
# X264_COMMIT is the commit number, and can be found here:
# http://git.videolan.org/?p=x264.git;a=shortlog;h=refs/heads/stable
#
# X264_REV requires a checkout the git revision for the version the port
# is being updated to. Then run version.sh against it.
#
# Bumping PORTREVISION for dependent ports? This is useful:
# cd $PORTSDIR; for x in $(find . -name "Makefile*" -print);
# do str=$(grep -i x264.so $x); if [[ -n $str ]] { echo "$x" }; done

PORTNAME=	x264
PORTVERSION=	0.${X264_BUILD}.${X264_REV}
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/x264/snapshots/ \
		http://samples.mplayerhq.hu/yuv4mpeg2/:pgo
DISTNAME=	${PORTNAME}-snapshot-${X264_SNAPSHOT}-2245-stable
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	x264
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT?=	H.264/MPEG-4 AVC Video Encoding (Front End CLI)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm>=1.2.0:${PORTSDIR}/devel/yasm \
		bash:${PORTSDIR}/shells/bash

X264_BUILD=	144
X264_REV=	2533
X264_COMMIT=	c8a773ebfca148ef04f5a60d42cbd7336af0baf6
X264_GITVER=	${X264_COMMIT:C/^(.......).*$/\1/g}
X264_SNAPSHOT=	20150629

USES?=		gmake pkgconfig tar:bzip2
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

OPTIONS_DEFINE?=	ASM DEBUG GCC GPAC LAVF PGO
OPTIONS_DEFAULT?=	ASM GPAC

GCC_DESC=		Use current GCC
GPAC_DESC=		MPEG-4 output support
LAVF_DESC=		libav* format input/output support (requires FFmpeg)

ASM_CONFIGURE_OFF=	--disable-asm

DEBUG_CONFIGURE_ON=	--enable-debug
DEBUG_CONFIGURE_OFF=	--enable-strip

GPAC_CONFIGURE_OFF=	--disable-gpac
GPAC_LIB_DEPENDS=	libgpac.so:${PORTSDIR}/multimedia/gpac-libgpac

LAVF_CONFIGURE_OFF=	--disable-swscale --disable-lavf
LAVF_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
			libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
			libavutil.so:${PORTSDIR}/multimedia/ffmpeg \
			libswscale.so:${PORTSDIR}/multimedia/ffmpeg

CONFIGURE_COMMON_ARGS=	--prefix=${PREFIX} \
			--extra-cflags="-I${LOCALBASE}/include" \
			--extra-ldflags="-L${LOCALBASE}/lib" \
			--disable-opencl \

CONFIGURE_ARGS?=	${CONFIGURE_COMMON_ARGS} \
			--system-libx264

CFLAGS_armv6+=		-mcpu=arm1136jf-s

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == "no"
PLIST_FILES=	bin/x264
LIB_DEPENDS=	libx264.so:${PORTSDIR}/multimedia/libx264
.endif

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
	@${REINPLACE_CMD} -e ' \
		s|/bin/bash|${LOCALBASE}/bin/bash|; \
		s|gpac_static|gpac|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e ' \
		s|bash|sh|; \
		s|VER="x"|VER="${X264_REV} ${X264_GITVER}"|; \
		s|VERSION=""|VERSION=" r${X264_REV} ${X264_GITVER}"|' \
		${WRKSRC}/version.sh

.if ${SLAVE_PORT} == "no"
pre-build:
	@(${RM} ${WRKSRC}/x264_config.h)
.endif

.include <bsd.port.mk>
