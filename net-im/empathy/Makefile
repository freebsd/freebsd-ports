# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/net-im/empathy/Makefile 19491 2014-04-14 15:07:51Z gusi $

PORTNAME=	empathy
PORTVERSION=	3.12.1
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		geoclue>=0:${PORTSDIR}/net/geoclue \
		itstool:${PORTSDIR}/textproc/itstool \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libgeocode-glib.so:${PORTSDIR}/net/geocode-glib \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libtelepathy.so:${PORTSDIR}/net-im/libtelepathy \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libtelepathy-farstream.so:${PORTSDIR}/net-im/telepathy-farstream \
		libtelepathy-logger.so:${PORTSDIR}/net-im/telepathy-logger \
		libfolks-telepathy.so:${PORTSDIR}/net-im/folks \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		geoclue>=0:${PORTSDIR}/net/geoclue \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 gnomeprefix
USE_PYTHON=	yes
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

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml \
		org.gnome.telepathy-account-widgets.gschema.xml

OPTIONS_DEFINE=	JABBER MSN IRC SALUT HAZE MAP CHEESE
OPTIONS_DEFAULT=JABBER MSN IRC SALUT      MAP
JABBER_DESC=	Enable jabber (XMPP) client support
MSN_DESC=	Enable MSN client support
IRC_DESC=	Enable IRC client support
SALUT_DESC=	Enable link-local (serverless) XMPP support
HAZE_DESC=	Enable libpurple protocol integration
MAP_DESC=	Enable graphical map support
CHEESE_DESC=	Enable cheese camera support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJABBER}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble
.endif

.if ${PORT_OPTIONS:MMSN}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-butterfly:${PORTSDIR}/net-im/telepathy-butterfly
.endif

.if ${PORT_OPTIONS:MIRC}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle
.endif

.if ${PORT_OPTIONS:MSALUT}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut
.endif

.if !defined(WITHOUT_HAZE)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze
.endif

.if ${PORT_OPTIONS:MMAP}
USE_GL=		gl
LIB_DEPENDS+=	libchamplain-0.12.so:${PORTSDIR}/graphics/libchamplain
CONFIGURE_ARGS+=--enable-map
PLIST_SUB+=	MAP=""
.else
CONFIGURE_ARGS+=--disable-map
PLIST_SUB+=	MAP="@comment "
.endif

.if ${PORT_OPTIONS:MCHEESE}
BUILD_DEPENDS+=	cheese>=0:${PORTSDIR}/multimedia/cheese
RUN_DEPENDS+=	cheese>=0:${PORTSDIR}/multimedia/cheese
CONFIGURE_ARGS+=--with-cheese
.else
CONFIGURE_ARGS+=--without-cheese
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|clutter-gst-1.0|clutter-gst-2.0|g ;\
		s|MISSION_CONTROL_PLUGINS_DIR=`pkg-config -|MISSION_CONTROL_PLUGINS_DIR=$${libdir}/`pkg-config -|g' \
			${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/empathy/libempathy-*3.12.1.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mission-control-plugins.0/mcp-account-manager-goa.so

.include <bsd.port.mk>
