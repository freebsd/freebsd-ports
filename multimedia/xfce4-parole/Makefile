# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parole
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	multimedia xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on GStreamer

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS=	--enable-notify-plugin \
		--enable-tray-plugin \
		--enable-taglib \
		--without-html-dir
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_XFCE=	configenv libmenu libutil
USE_XORG=	x11 sm
USE_LDCONFIG=	yes
USES=		desktop-file-utils pathfix pkgconfig gmake

OPTIONS_DEFINE=	NLS
OPTIONS_SINGLE=	GSTREAMER
# GST01 (GStreamer 0.10), GST10 (GStreamer 1.0)
OPTIONS_SINGLE_GSTREAMER=	GST01 GST10
OPTIONS_GROUP=	GST_PLUG
OPTIONS_GROUP_GST_PLUG=	CDDA HTTP
OPTIONS_DEFAULT=	GST01 NLS
CDDA_DESC=	CD audio (cdparanoia)
HTTP_DESC=	HTTP streaming (libsoup)
GST01_DESC=	GStreamer 0.10
GST10_DESC=	GStreamer 1.0
GST_PLUG_DESC=	Additional GStreamer plugins

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
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
# Fix .rc files path
	@${REINPLACE_CMD} -e 's|xfce4/src/misc|${PORTNAME}|g' \
		${WRKSRC}/src/common/parole-rc-utils.h

.include <bsd.port.mk>
