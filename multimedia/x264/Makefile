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
PORTREVISION?=	3
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

BUILD_DEPENDS=	yasm>=1.2.0:devel/yasm \
		bash:shells/bash
LIB_DEPENDS?=	libx264.so:multimedia/libx264

X264_BUILD=	144
X264_REV=	2533
X264_COMMIT=	c8a773ebfca148ef04f5a60d42cbd7336af0baf6
X264_GITVER=	${X264_COMMIT:C/^(.......).*$/\1/g}
X264_SNAPSHOT=	20150629

USES?=		pkgconfig
USES+=		gmake localbase shebangfix tar:bzip2
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
SHEBANG_FILES=	configure
PLIST_FILES?=	bin/x264

OPTIONS_DEFINE+=	ASM DEBUG FFMS GCC LAVF PGO SWSCALE
OPTIONS_RADIO+=		MP4
OPTIONS_RADIO_MP4+=	GPAC LSMASH
OPTIONS_DEFAULT+=	ASM LSMASH

FFMS_DESC=		FFmpeg Source input support
GPAC_DESC=		GPAC library support
LAVF_DESC=		libav* format input support (requires FFmpeg)
LSMASH_DESC=		L-SMASH library support
MP4_DESC=		MPEG-4 output
SWSCALE_DESC=		Resize video filter

ASM_CONFIGURE_OFF=	--disable-asm

DEBUG_CONFIGURE_ON=	--enable-debug
DEBUG_CONFIGURE_OFF=	--enable-strip

FFMS_LIB_DEPENDS=	libffms2.so:multimedia/ffms2
FFMS_CONFIGURE_OFF=	--disable-ffms
FFMS_IMPLIES=		SWSCALE

GCC_VARS=		USE_GCC=yes

GPAC_CONFIGURE_OFF=	--disable-gpac
GPAC_LIB_DEPENDS=	libgpac.so:multimedia/gpac-libgpac

LAVF_CONFIGURE_OFF=	--disable-lavf
LAVF_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavformat.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
LAVF_IMPLIES=		SWSCALE

LSMASH_LIB_DEPENDS=	liblsmash.so:multimedia/l-smash
LSMASH_CONFIGURE_OFF=	--disable-lsmash

PGO_DISTFILES=		${Y4M_VIDEO_DISTFILE}:pgo
PGO_MAKE_ENV=		VIDS="${WRKDIR}/${Y4M_VIDEO}"
PGO_ALL_TARGET=		fprofiled
# y4m sample video
Y4M_VIDEO=		example.y4m
Y4M_VIDEO_DISTFILE=	example.y4m.bz2
PGO_VARS=		USE_GCC=any \
			RESTRICTED="${Y4M_VIDEO_DISTFILE} file may not be mirrored" \
			RESTRICTED_FILES="${Y4M_VIDEO_DISTFILE}"

SWSCALE_CONFIGURE_OFF=	--disable-swscale
SWSCALE_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
			libswscale.so:multimedia/ffmpeg

CONFIGURE_ARGS?=	--system-libx264
CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
			--extra-cflags="${CPPFLAGS} ${CFLAGS}" \
			--extra-ldflags="${LDFLAGS}" \
			--disable-opencl \

CFLAGS_armv6+=		-mcpu=arm1136jf-s

post-extract-PGO-on:
	@${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${Y4M_VIDEO_DISTFILE} \
		>${WRKDIR}/${Y4M_VIDEO}

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|gpac_static|gpac|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e ' \
		s|bash|sh|; \
		s|VER="x"|VER="${X264_REV} ${X264_GITVER}"|; \
		s|VERSION=""|VERSION=" r${X264_REV} ${X264_GITVER}"|' \
		${WRKSRC}/version.sh

.if !target(pre-build)
pre-build:
	@(${RM} ${WRKSRC}/x264_config.h)
.endif

.include <bsd.port.mk>
