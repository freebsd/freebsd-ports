# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parole
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	multimedia xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on GStreamer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify \
		libtag.so:audio/taglib
RUN_DEPENDS=	xdg-screensaver:devel/xdg-utils

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-notify-plugin \
		--enable-tray-plugin \
		--enable-taglib \
		--disable-mpris2-plugin \
		--without-html-dir \
		--with-gstreamer=1.0
USE_GNOME=	cairo gtk30 glib20 intltool intlhack
USE_GSTREAMER1=	core faad flac wavpack rtmp x
USE_XFCE=	panel
USE_XORG=	ice sm x11
USE_LDCONFIG=	yes
USES=		desktop-file-utils gettext-tools gmake libtool pkgconfig \
		tar:bzip2 xfce:gtk3
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_GROUP=		GST_PLUG
OPTIONS_GROUP_GST_PLUG=	CDDA HTTP
OPTIONS_DEFAULT=	HTTP
OPTIONS_SUB=		yes

CDDA_USE=		gstreamer1=cdparanoia
GST_PLUG_DESC=		Additional GStreamer plugins
HTTP_DESC=		HTTP streaming (libsoup)
HTTP_USE=		gstreamer1=soup
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
# Fix .rc files path
	@${REINPLACE_CMD} -e 's|xfce4/src/misc|${PORTNAME}|g' \
		${WRKSRC}/src/common/parole-rc-utils.h

.include <bsd.port.mk>
