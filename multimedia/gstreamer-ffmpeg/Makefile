# New ports collection makefile for:	gstreamer ffmpeg
# Date created:		Thu Feb 26 20:10:39 CET 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-ffmpeg/
PKGNAMESUFFIX=	-ffmpeg
DISTNAME=	gst-ffmpeg-${PORTVERSION}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	GStreamer plug-in for manipulating MPEG video streams

LIB_DEPENDS=	gstreamer-0.8.4:${PORTSDIR}/multimedia/gstreamer

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB=	\
		VERSION="${GST_VERSION}"
INSTALLS_SHLIB=	yes

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
GST_VERSION=${PORTVERSION:C/..$//}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|make|${GMAKE}|' \
		${WRKSRC}/gst-libs/ext/Makefile.in

post-install:
# register plugins
	-@${X11BASE}/bin/gst-register-${GST_VERSION} 2>/dev/null

.include <bsd.port.post.mk>
