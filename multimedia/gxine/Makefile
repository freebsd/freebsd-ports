# Created by: Grigori Goronzy <greg@chown.ath.cx>
# $FreeBSD$

PORTNAME=	gxine
PORTVERSION=	0.5.907
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	SF/xine/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative GUI for the Xine media player

LICENSE=	GPLv2

LIB_DEPENDS=	libnspr4.so:${PORTSDIR}/devel/nspr \
		libmozjs185.so:${PORTSDIR}/lang/spidermonkey185 \
		libxine.so:${PORTSDIR}/multimedia/libxine

OPTIONS_DEFINE=	MOZILLA_PLUGIN GNOME LIRC
MOZILLA_PLUGIN_DESC=	Mozilla plugin

USES=		gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-hal --with-libintl-prefix=${LOCALBASE}
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOZILLA_PLUGIN}
USE_XORG+=	xaw
USES+=		webplugin:native
WEBPLUGIN_DIR=	${PREFIX}/lib/gxine
WEBPLUGIN_FILES=gxineplugin.so
PLIST_SUB+=	MOZILLA_PLUGIN=""
.else
CONFIGURE_ARGS+=--without-browser-plugin
PLIST_SUB+=	MOZILLA_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
BUILD_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
CONFIGURE_ARGS+=--with-dbus
.else
CONFIGURE_ARGS+=--disable-integration-wizard --without-dbus
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	liblirc_client.so:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS/s|-I/usr/local/include|| ; \
		 /CFLAGS/s|-L/usr/local/lib|| ; \
		 /CPPFLAGS/s|-I/usr/local/include|| ; \
		 s|XINE_LIST=.*|XINE_LIST=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@MAKE_PNG_TRUE@|#|' ${WRKSRC}/pixmaps/Makefile.in

.include <bsd.port.mk>
