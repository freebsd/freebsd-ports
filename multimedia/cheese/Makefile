PORTNAME=	cheese
PORTVERSION=	41.1
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photobooth-inspired app for taking pictures and videos from webcam

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		gnome-video-effects>=0:graphics/gnome-video-effects \
		vala>=0.14.0:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra-gtk.so:audio/libcanberra-gtk2 \
		libcanberra.so:audio/libcanberra \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-gst-3.0.so:multimedia/clutter-gst3
RUN_DEPENDS=	gnome-video-effects>=0:graphics/gnome-video-effects

PORTSCOUT=	limitw:1,even

USES=		gettext gl gnome gstreamer localbase:ldflags pkgconfig meson tar:xz xorg
USE_GNOME=	cairo librsvg2 gnomedesktop3 libxml2:build introspection:build
USE_GL=		egl
USE_XORG=	xi xext xdamage xfixes xcomposite xrandr xxf86vm x11
USE_GSTREAMER=	bad good jpeg ogg theora v4l2 vorbis vpx
USE_LDCONFIG=	yes
CPPFLAGS+=	-Wno-format-nonliteral

MESON_ARGS=	-Dgtk_doc=false \
		-Dman=false

GLIB_SCHEMAS=	org.gnome.Cheese.gschema.xml

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|canberra-gtk\.h|canberra-gtk2/canberra-gtk.h|'

.include <bsd.port.mk>
