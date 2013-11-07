# Created by: Grigori Goronzy <greg@chown.ath.cx>
# $FreeBSD$

PORTNAME=	gxine
PORTVERSION=	0.5.907
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/xine/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative GUI for the Xine media player

LICENSE=	GPLv2

BROKEN=		Does not build with recent libxul

LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr \
		xine.2:${PORTSDIR}/multimedia/libxine

OPTIONS_DEFINE=	MOZILLA_PLUGIN GNOME LIRC
MOZILLA_PLUGIN_DESC=	Mozilla plugin

USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20
USE_GECKO=	libxul
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"
CONFIGURE_ARGS=	--enable-mozjs --disable-ffjs --disable-seajs \
		--without-hal --with-libintl-prefix=${LOCALBASE}
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MANLANG=	"" de es
MAN1=		gxine.1 gxine_client.1
MANCOMPRESSED=	no

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOZILLA_PLUGIN}
USE_XORG+=	xaw
USE_WEBPLUGINS=	native
WEBPLUGINS_DIR=	${PREFIX}/lib/gxine
WEBPLUGINS_FILES=gxineplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
PLIST_SUB+=	MOZILLA_PLUGIN=""
.else
CONFIGURE_ARGS+=--without-browser-plugin
PLIST_SUB+=	MOZILLA_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
BUILD_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
CONFIGURE_ARGS+=--with-dbus
.else
CONFIGURE_ARGS+=--disable-integration-wizard --without-dbus
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	lirc_client.2:${PORTSDIR}/comms/lirc
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
