# New ports collection makefile for:	gstreamer ffmpeg
# Date created:		Thu Feb 26 20:10:39 CET 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-ffmpeg/Makefile,v 1.14 2006/07/20 13:40:27 ahze Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.8
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-ffmpeg/
PKGNAMESUFFIX=	-ffmpeg
DISTNAME=	gst-ffmpeg-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in for manipulating MPEG video streams

CFLAGS:=	${CFLAGS} -O2
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnometarget
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS} -fno-force-addr" \
		LDFLAGS="${LDFLAGS}"
PLIST_SUB=	\
		VERSION="${GST_VERSION}"
WITHOUT_CPU_CFLAGS=	yes

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
GST_VERSION=${PORTVERSION:C/..$//}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|make|${GMAKE}|' \
		${WRKSRC}/gst-libs/ext/Makefile.in

.include <bsd.port.post.mk>
