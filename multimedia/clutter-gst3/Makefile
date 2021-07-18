# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	clutter-gst
PORTVERSION=	3.0.27
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libcogl-path.so:graphics/cogl \
		libfribidi.so:converters/fribidi \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext-runtime gl gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz xorg
USE_GNOME=	atk cairo gdkpixbuf2 gnomeprefix introspection:build pango
GNU_CONFIGURE=	yes
USE_GL=		gl egl
USE_GSTREAMER1=	yes
USE_XORG=	xcomposite xdamage xext xfixes xi xrandr x11
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
CONFIGURE_ARGS=	--disable-udev

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

# The clutter-gst gstreamer plugin is not parrallel installable with
# the 2.0 version. But we install it anyway since all GNOME users
# are switched.

.include <bsd.port.mk>
