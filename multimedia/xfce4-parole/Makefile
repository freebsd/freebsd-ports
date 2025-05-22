PORTNAME=	parole
PORTVERSION=	4.20.0
CATEGORIES=	multimedia xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on GStreamer
WWW=		https://docs.xfce.org/apps/parole/start

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify \
		libtag_c.so:audio/taglib
RUN_DEPENDS=	xdg-screensaver:devel/xdg-utils

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		gstreamer meson pkgconfig tar:xz xfce xorg
USE_GNOME=	glib20 gtk30
USE_GSTREAMER=	core faad flac wavpack x
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11

MESON_ARGS=	-Dgtk-doc=false \
		-Dmpris2-plugin=enabled \
		-Dnotify-plugin=enabled \
		-Dtaglib=enabled \
		-Dtray-plugin=enabled \
		-Dx11=enabled

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	HTTP WAYLAND
OPTIONS_GROUP=		GST_PLUG
OPTIONS_GROUP_GST_PLUG=	CDDA HTTP
OPTIONS_SUB=		yes

GST_PLUG_DESC=	Additional GStreamer plugins
HTTP_DESC=	HTTP streaming (libsoup)

CDDA_USE=	GSTREAMER=cdparanoia

HTTP_USE=	GSTREAMER=soup

NLS_USES=	gettext-runtime

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_MESON_ENABLED=	wayland

post-patch:
# Fix .rc files path
	@${REINPLACE_CMD} -e 's|xfce4/src/misc|${PORTNAME}|g' \
		${WRKSRC}/src/common/parole-rc-utils.h

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
