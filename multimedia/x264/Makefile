# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	x264
PORTVERSION=	0.${X264_BUILD}.${X264_REV}
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/x264/snapshots/ \
		http://samples.mplayerhq.hu/yuv4mpeg2/:pgo
DISTNAME=	${PORTNAME}-snapshot-${X264_SNAP}-2245-stable
DISTFILES=	${PORTNAME}-snapshot-${X264_SNAP}-2245-stable${EXTRACT_SUFX}
DIST_SUBDIR=	x264
EXTRACT_ONLY=	${PORTNAME}-snapshot-${X264_SNAP}-2245-stable${EXTRACT_SUFX}

MAINTAINER=	mm@FreeBSD.org
COMMENT?=	Library and tool for encoding H.264/AVC video streams

BUILD_DEPENDS=	yasm>=0.6.0:${PORTSDIR}/devel/yasm

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

X264_BUILD=	116
X264_REV=	2076
X264_SNAP=	20111009

USE_BZIP2=	yes
EXTRACT_AFTER_ARGS?=	| ${TAR} -xf - --exclude .svn
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	ASM "Assembly optimizations (devel/binutils)" On \
		DEBUG "Enable Debugging" Off \
		PGO "Enable Profile-Guided Optimization" Off \
		GCC44 "Use gcc 4.4+ (implies WITH_ASM)" Off \
		GPAC "Enable MPEG-4 Output" On \
		X11_OUTPUT "Enable X11 Output" Off

CONFIGURE_ARGS+=	--extra-cflags="${CPPFLAGS} ${CFLAGS} -fPIC -I${LOCALBASE}/include" \
			--extra-ldflags="${LDFLAGS} -L${LOCALBASE}/lib" \
			--enable-static --enable-shared

PLIST_SUB+=	X264_BUILD=${X264_BUILD}

.include <bsd.port.pre.mk>

.if defined(WITH_GCC44)
USE_GCC?=	4.4+
.endif

.if !defined(WITHOUT_ASM) || defined(WITH_GCC44)
BUILD_DEPENDS+=		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=		COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=		COMPILER_PATH=${LOCALBASE}/bin
.else
CONFIGURE_ARGS+=		--disable-asm
.endif

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

CONFIGURE_ENV+=	ARCH= \
		TARGET_ARCH=
MAKE_ENV+=	ARCH= \
		TARGET_ARCH=

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PGO) && ${SLAVE_PORT:L}!="yes"
# y4m sample video
Y4M_VIDEO=example.y4m
Y4M_VIDEO_DISTFILE=example.y4m.bz2

DISTFILES+=	${Y4M_VIDEO_DISTFILE}:pgo
ALL_TARGET=	fprofiled
MAKE_ENV+=	VIDS="${WRKDIR}/${Y4M_VIDEO}"

RESTRICTED=	${Y4M_VIDEO_DISTFILE} file may not be mirrored
RESTRICTED_FILES=	${Y4M_VIDEO_DISTFILE}
.endif

.if !defined(WITHOUT_GPAC)
BUILD_DEPENDS+=		gpac-libgpac>=0.4.5,1:${PORTSDIR}/multimedia/gpac-libgpac
LIB_DEPENDS+=		gpac.1:${PORTSDIR}/multimedia/gpac-libgpac
.else
CONFIGURE_ARGS+=	--disable-gpac
.endif

.if defined(WITH_X11_OUTPUT)
CONFIGURE_ARGS+=	--enable-visualize
USE_XORG=	x11
.endif

post-extract:
.if defined(WITH_PGO) && ${SLAVE_PORT:L}!="yes"
	@( cd ${WRKDIR} && ${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${Y4M_VIDEO_DISTFILE} > ${Y4M_VIDEO} )
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|bash|sh|; \
		s|gpac_static|gpac|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/version.sh
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile
.if !defined(WITH_GCC44)
	@${REINPLACE_CMD} -e 's|$$(CC) -shared -o|COMPILER_PATH= $$(CC) -shared -o|g' \
		-e 's|$$(CC) -o|COMPILER_PATH= $$(CC) -o|g' \
		${WRKSRC}/Makefile
.endif

.if ${SLAVE_PORT:L}=="no"
.if 0 # BROKEN
post-build:
	cd ${WRKSRC}/tools && ${MAKE} avc2avi

pre-install:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/x264.pc

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/avc2avi ${PREFIX}/bin
.endif # BROKEN
.endif

.include <bsd.port.post.mk>
