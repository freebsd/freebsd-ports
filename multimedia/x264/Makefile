# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x264
PORTVERSION=	0.0.20060521
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/x264/snapshots/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION:S/0.0.//}-2245

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia library and tool for encoding H.264/AVC video streams

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
ALL_TARGET=	default
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes

PLIST_FILES=	bin/x264 \
		include/x264.h \
		lib/libx264.a \
		lib/libx264.so \
		lib/libx264.so.47 \
		libdata/pkgconfig/x264.pc

OPTIONS=	GPAC "Enable MPEG-4 Output" On \
		DEBUG "Enable Debugging" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off \
		X11_OUTPUT "Enable X11 Output" Off

CONFIGURE_ARGS+=	--extra-cflags="${CPPFLAGS} ${CFLAGS} -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
			--extra-ldflags="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib" \
			--enable-shared

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ENV+=	ARCH_X86="1"
.endif

.if ${ARCH}=="amd64" || ${ARCH}=="sparc64"
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
MAKE_ENV+=	ARCH_X86_64="1"
.endif

MAKE_ARGS+=	ARCH=${ARCH}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -funroll-loops -ffast-math
.endif

.if !defined(WITHOUT_GPAC)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libgpac_static.a:${PORTSDIR}/multimedia/gpac-libgpac
CONFIGURE_ARGS+=	--enable-mp4-output
.endif

.if defined(WITH_X11_OUTPUT)
CONFIGURE_ARGS+=	--enable-visualize
USE_XLIB=		yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile

pre-install:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/x264.pc

.include <bsd.port.post.mk>
