# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#
# Updating notes:
# We use the nightly tarballs for the *stable* branch of the git repo.
# X264_BUILD is the "core" number, and can always be found in x264.h.
# X264_COMMIT is the commit number, and can be found here:
# http://git.videolan.org/?p=x264.git;a=shortlog;h=refs/heads/stable
# To get X264_REV, you must checkout the git revision for the version to
# which you wish to update, and then run version.sh against it.
# Don't forget to update these for multimedia/libx264 as well:
# X264_BUILD, X264_REV, X264_COMMIT, X264_SNAPSHOT
#
# distinfo for this port and libx264 should always be *identical*.
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
COMMENT=	Tool for encoding H.264/AVC video streams

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm>=0.6.0:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libx264.so:${PORTSDIR}/multimedia/libx264

X264_BUILD=	142
X264_REV=	2455
X264_COMMIT=	021c0dc6c95c1bc239c9db78a80dd85fc856a4dd
X264_GITVER=	${X264_COMMIT:C/^(.......).*$/\1/g}
X264_SNAPSHOT=	20140827

USES=		gmake tar:bzip2 pkgconfig
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		ASM DEBUG PGO GCC GPAC LAVF
OPTIONS_DEFAULT=	ASM GPAC
ASM_DESC=		Enable Assembly Optimizations
DEBUG_DESC=		Generate Debugging Symbols
PGO_DESC=		Use Profile-Guided Optimization
GCC_DESC=		Use current GCC
GPAC_DESC=		Enable MPEG-4 Output
LAVF_DESC=		Enable libav* format input/output support (requires ffmpeg)

CONFIGURE_ARGS+=	--extra-cflags="-I${LOCALBASE}/include" \
			--extra-ldflags="-L${LOCALBASE}/lib" \
			--disable-opencl \
			--system-libx264

PLIST_SUB+=	X264_BUILD=${X264_BUILD}
PLIST_FILES=	bin/x264

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

.if ${PORT_OPTIONS:MLAVF}
LIB_DEPENDS+=		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
LIB_DEPENDS+=		libavformat.so:${PORTSDIR}/multimedia/ffmpeg
LIB_DEPENDS+=		libavutil.so:${PORTSDIR}/multimedia/ffmpeg
LIB_DEPENDS+=		libswscale.so:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--disable-swscale --disable-lavf
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
	@${REINPLACE_CMD} -e 's|bash|sh|; \
		s|VER="x"|VER="${X264_REV} ${X264_GITVER}"|; \
		s|VERSION=""|VERSION=" r${X264_REV} ${X264_GITVER}"|' \
		${WRKSRC}/version.sh
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/x264

.include <bsd.port.mk>
