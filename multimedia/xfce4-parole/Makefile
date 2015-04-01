# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parole
PORTVERSION=	0.8.0
CATEGORIES=	multimedia xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on GStreamer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	gnome-icon-theme-symbolic>=3.6:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-notify-plugin \
		--enable-tray-plugin \
		--enable-taglib \
		--disable-mpris2-plugin \
		--without-html-dir
USE_GNOME=	gtk30 glib20 intltool intlhack
USE_XFCE=	panel
USE_XORG=	x11 sm
USE_LDCONFIG=	yes
USES=		desktop-file-utils pkgconfig gmake libtool gettext-tools \
		xfce:gtk3 tar:bzip2

OPTIONS_DEFINE=	CLUTTER NLS
OPTIONS_SINGLE=	GSTREAMER
# GST01 (GStreamer 0.10), GST10 (GStreamer 1.0)
OPTIONS_SINGLE_GSTREAMER=	GST01 GST10
OPTIONS_GROUP=	GST_PLUG
OPTIONS_GROUP_GST_PLUG=	CDDA HTTP
# Since 0.5.91 release, GStreamer 1.0 is enabled by default
OPTIONS_DEFAULT=	GST10 HTTP NLS
HTTP_DESC=	HTTP streaming (libsoup)
GST01_DESC=	GStreamer 0.10
GST10_DESC=	GStreamer 1.0
GST_PLUG_DESC=	Additional GStreamer plugins
CLUTTER_DESC=	Clutter (OpenGL) backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGST01}
USE_GSTREAMER=	core faad flac wavpack
CONFIGURE_ARGS+=--with-gstreamer=0.10
.endif

.if ${PORT_OPTIONS:MGST10}
USE_GSTREAMER1=	core faad flac wavpack rtmp x
CONFIGURE_ARGS+=--with-gstreamer=1.0
.endif

.if ${PORT_OPTIONS:MCDDA}
.if ${PORT_OPTIONS:MGST01}
USE_GSTREAMER+=	cdparanoia
.endif
.if ${PORT_OPTIONS:MGST10}
USE_GSTREAMER1+= cdparanoia
.endif
.endif

.if ${PORT_OPTIONS:MHTTP}
.if ${PORT_OPTIONS:MGST01}
USE_GSTREAMER+=	soup
.endif
.if ${PORT_OPTIONS:MGST10}
USE_GSTREAMER1+= soup
.endif
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext-runtime
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MCLUTTER} && ${PORT_OPTIONS:MGST10}
LIB_DEPENDS+=	libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3
CONFIGURE_ARGS+=--enable-clutter
.else
CONFIGURE_ARGS+=--disable-clutter
.endif

post-patch:
# Fix .rc files path
	@${REINPLACE_CMD} -e 's|xfce4/src/misc|${PORTNAME}|g' \
		${WRKSRC}/src/common/parole-rc-utils.h

.include <bsd.port.mk>
