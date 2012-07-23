# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	x264
PORTVERSION=	0.${X264_BUILD}.${X264_REV}
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://samples.mplayerhq.hu/yuv4mpeg2/:pgo
MASTER_SITE_SUBDIR=	mm/x264
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${X264_GITVER}
DISTFILES=	${DISTNAME}.tar.xz
DIST_SUBDIR=	x264
EXTRACT_ONLY=	${DISTFILES}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Library and tool for encoding H.264/AVC video streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm>=0.6.0:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

CONFLICTS=	x264-0.*

DEPRECATED=	x264 github development makes this port obsolete
EXPIRATION_DATE=	2012-08-23

LATEST_LINK=	x264-devel

X264_BUILD=	124
X264_REV=	2197
X264_COMMIT=	69a0443e7d8ab032a7f3c3468a42177d5e64daa2
X264_GITVER=	${X264_COMMIT:C/^(.......).*$/\1/g}

USE_XZ=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	DEBUG "Enable Debugging" Off \
		PGO "Enable Profile-Guided Optimization" Off \
		GCC44 "Use gcc 4.4+" Off \
		GPAC "Enable MPEG-4 Output" On \
		X11_OUTPUT "Enable X11 Output" Off

CONFIGURE_ARGS+=	--extra-cflags="${CPPFLAGS} ${CFLAGS} -fPIC -I${LOCALBASE}/include" \
			--extra-ldflags="${LDFLAGS} -L${LOCALBASE}/lib" \
			--enable-static --enable-shared

CONFIGURE_ENV+=		COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=		COMPILER_PATH=${LOCALBASE}/bin

PLIST_SUB+=		X264_BUILD=${X264_BUILD}

.include <bsd.port.pre.mk>

.if defined(WITH_GCC44)
USE_GCC?=	4.4+
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
CONFIGURE_ARGS+=	--enable-gpac
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
		s|/bin/bash|${LOCALBASE}/bin/bash|; \
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
