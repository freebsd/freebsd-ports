# Created by: Grigori Goronzy <greg@chown.ath.cx>
# $FreeBSD$

PORTNAME=	gxine
PORTVERSION=	0.5.910
CATEGORIES=	multimedia
MASTER_SITES=	SF/xine/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative GUI for the Xine media player

LICENSE=	GPLv2

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libmozjs185.so:lang/spidermonkey185 \
		libxine.so:multimedia/libxine

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-hal --with-libintl-prefix=${LOCALBASE} --with-gtk3
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm

OPTIONS_DEFINE=		GNOME LIRC WEBPLUGIN
OPTIONS_SUB=		yes

GNOME_BUILD_DEPENDS=	gnome-screensaver:x11/gnome-screensaver
GNOME_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
GNOME_RUN_DEPENDS=	gnome-screensaver:x11/gnome-screensaver
GNOME_CONFIGURE_ON=	--with-dbus
GNOME_CONFIGURE_OFF=	--disable-integration-wizard --without-dbus
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ON=	--enable-lirc
LIRC_CONFIGURE_OFF=	--disable-lirc
WEBPLUGIN_DESC=		Build and/or install Web browser plugins
WEBPLUGIN_USE=		xorg=xaw
WEBPLUGIN_USES=		webplugin:native
WEBPLUGIN_CONFIGURE_OFF=	--without-browser-plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBPLUGIN}
WEBPLUGIN_DIR=	${PREFIX}/lib/gxine
WEBPLUGIN_FILES=gxineplugin.so
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS/s|-I/usr/local/include|| ; \
		 /CFLAGS/s|-L/usr/local/lib|| ; \
		 /CPPFLAGS/s|-I/usr/local/include|| ; \
		 s|XINE_LIST=.*|XINE_LIST=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@MAKE_PNG_TRUE@|#|' ${WRKSRC}/pixmaps/Makefile.in

post-install:
	${CP} ${WRKSRC}/pixmaps/logo.mpv ${STAGEDIR}${PREFIX}/share/gxine
.if ${PORT_OPTIONS:MWEBPLUGIN}
	@${STRIP_CMD} ${STAGEDIR}${WEBPLUGIN_DIR}/${WEBPLUGIN_FILES}
.endif

.include <bsd.port.mk>
