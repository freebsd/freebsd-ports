# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	uget
PORTVERSION=	1.10.4
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	urlget/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Download manager application

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

USES=	gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 intltool intlhack
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GNUTLS NLS
OPTIONS_RADIO=	GSTREAMER
OPTIONS_RADIO_GSTREAMER=	GST01 GST10
OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	PLUG_ARIA PLUG_CURL
OPTIONS_DEFAULT=	GNUTLS GST10 NLS PLUG_CURL
# GNUTLS option is currently broken, fixed in 'master' branch
OPTIONS_EXCLUDE=	GNUTLS

GST010_DESC=	GStreamer 0.10
GST10_DESC=	GStreamer 1.0
PLUG_ARIA_DESC=	Aria2 plugin
PLUG_CURL_DESC=	cURL plugin

CONFIGURE_ARGS=--enable-appindicator=no \
	--disable-pwmd \
	--enable-hidden

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls \
	libgcrypt.so:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--enable-gnutls
.else
CONFIGURE_ARGS+=--disable-gnutls
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGST10}
USE_GSTREAMER1=	yes
CONFIGURE_ARGS+=--enable-gstreamer
.endif

.if ${PORT_OPTIONS:MGST01}
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=--enable-gstreamer
.endif

.if ! ${PORT_OPTIONS:MGST10} && ! ${PORT_OPTIONS:MGST01}
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MPLUG_ARIA}
BUILD_DEPENDS=	aria2c:${PORTSDIR}/www/aria2
CONFIGURE_ARGS+=--enable-plugin-aria2
.else
CONFIGURE_ARGS+=--disable-plugin-aria2
.endif

.if ${PORT_OPTIONS:MPLUG_CURL}
BUILD_DEPENDS=	curl-config:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--enable-plugin-curl
.else
CONFIGURE_ARGS+=--disable-plugin-curl
.endif

post-install:
	cd ${WRKSRC}/uget-cmd && \
		${INSTALL_PROGRAM} uget-cmd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
