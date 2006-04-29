# New ports collection makefile for:	gstreamer ffmpeg
# Date created:		Thu Feb 26 20:10:39 CET 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-ffmpeg/
PKGNAMESUFFIX=	-ffmpeg
DISTNAME=	gst-ffmpeg-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GStreamer plug-in for manipulating MPEG video streams

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -fno-force-addr" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB=	\
		VERSION="${GST_VERSION}"
WITHOUT_CPU_CFLAGS=	yes

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
GST_VERSION=${PORTVERSION:C/..$//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gst-libs_ext_ffmpeg_libavformat_nut.c
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|make|${GMAKE}|' \
		${WRKSRC}/gst-libs/ext/Makefile.in

.include <bsd.port.post.mk>
