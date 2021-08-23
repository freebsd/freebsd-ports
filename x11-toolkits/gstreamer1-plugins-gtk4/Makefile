PORTNAME=	gstreamer1-plugins-gtk4
DISTVERSION=	1.16.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/${DISTNAME:S/-${DISTVERSION}/\/${DISTVERSION:R}/} \
		https://gstreamer.freedesktop.org/src/${DISTNAME:S/-${DISTVERSION}//}/
DISTNAME=	gst-plugins-good-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GStreamer GTK4 video sink plugin

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gtk40
USE_GSTREAMER1=	gl
MESON_ARGS=	--auto-features=disabled -Dgtk4=enabled
PLIST_FILES=	lib/gstreamer-1.0/libgstgtk4.so

.include <bsd.port.mk>
