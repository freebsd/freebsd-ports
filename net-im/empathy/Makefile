# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	empathy
PORTVERSION=	3.12.11
PORTREVISION=	1
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		ca_root_nss>=0:security/ca_root_nss \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		geoclue>=0:net/geoclue \
		itstool:textproc/itstool \
		mc-tool:net-im/telepathy-mission-control
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libgeocode-glib.so:net/geocode-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpulse.so:audio/pulseaudio \
		libtelepathy.so:net-im/libtelepathy \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libfolks-telepathy.so:net-im/folks \
		libnotify.so:devel/libnotify \
		libgcr-3.so:security/gcr \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libclutter-gst-2.0.so:multimedia/clutter-gst \
		libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		ca_root_nss>=0:security/ca_root_nss \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		geoclue>=0:net/geoclue \
		mc-tool:net-im/telepathy-mission-control

USES=		gettext gmake gnome libtool pathfix pkgconfig python tar:xz
USE_GNOME=	evolutiondataserver3 intlhack
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	YES
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-Werror \
		--enable-goa \
		--enable-gst-1.0=yes \
		--enable-location=yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml \
		org.gnome.telepathy-account-widgets.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JABBER MSN IRC SALUT HAZE MAP CHEESE
OPTIONS_DEFAULT=JABBER MSN IRC SALUT      MAP
JABBER_DESC=	Enable jabber (XMPP) client support
MSN_DESC=	Enable MSN client support
IRC_DESC=	Enable IRC client support
SALUT_DESC=	Enable link-local (serverless) XMPP support
HAZE_DESC=	Enable libpurple protocol integration
MAP_DESC=	Enable graphical map support
CHEESE_DESC=	Enable cheese camera support
JABBER_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-gabble:net-im/telepathy-gabble
MSN_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-butterfly:net-im/telepathy-butterfly
IRC_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-idle:net-im/telepathy-idle
SALUT_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-salut:net-im/telepathy-salut
HAZE_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-haze:net-im/telepathy-haze
MAP_USE=		GL=gl
MAP_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain
MAP_CONFIGURE_ENABLE=	map
CHEESE_BUILD_DEPENDS=	cheese>=0:multimedia/cheese
CHEESE_RUN_DEPENDS=	cheese>=0:multimedia/cheese
CHEESE_CONFIGURE_WITH=	cheese

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|clutter-gst-1.0|clutter-gst-2.0|g ;\
		s|MISSION_CONTROL_PLUGINS_DIR=`pkg-config -|MISSION_CONTROL_PLUGINS_DIR=$${libdir}/`pkg-config -|g' \
			${WRKSRC}/configure

# workaround wierd bug that happened in 3.12.11.
post-install:
	@${MV} ${STAGEDIR}/mission-control-plugins.0 \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
