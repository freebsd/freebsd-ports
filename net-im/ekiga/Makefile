# Created by: Charlie & <root@ws.ipfw.ru>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/ekiga/Makefile 19954 2014-10-15 10:03:57Z kwm $

PORTNAME=	ekiga
PORTVERSION=	4.0.1
PORTREVISION=	8
CATEGORIES=	net-im
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VoIP and video conferencing application

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		gnome-icon-theme>=3.0.0:misc/gnome-icon-theme
LIB_DEPENDS=	libboost_signals.so:devel/boost-libs \
		libopal.so:net/opal \
		libv4l2.so:multimedia/libv4l
RUN_DEPENDS=	gnome-icon-theme>=3.0.0:misc/gnome-icon-theme

GNU_CONFIGURE=	yes
USES=		cpe gettext gmake libtool pathfix perl5 pkgconfig \
		tar:xz
USE_XORG=	xv
USE_GNOME=	gtk20 intlhack libxml2
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-I${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	LDAP NOTIFY EVOLUTION GCONF DBUS AVAHI GNOMEHELP
OPTIONS_DEFAULT=NOTIFY DBUS GCONF AVAHI

EVOLUTION_DESC=	Evolution data server support
GNOMEHELP_DESC=	Build Ekiga help files

#OPTIONS_GROUP=	EXP
#OPTIONS_GROUP_EXP=	KDE KAB GSTREAMER XCAP LOUDMOUTH
EXP_DESC=	Experimental features
KDE_DESC=	KDE 4 support
KAB_DESC=	KAddressBook support (implies KDE option)
GSTREAMER_DESC=	Gstreamer support
XCAP_DESC=	Remote contact storage via HTTP in xml format
LOUDMOUTH_DESC=	XMPP (jabber) support

# Note that h.323 support is enabled when opal is build with it.

.include <bsd.port.options.mk>

PLIST_SUB+=	VERSION=${PORTVERSION}

.if ${PORT_OPTIONS:MKDE} || ${PORT_OPTIONS:MKAB}
USE_KDE4=	kdelibs
USE_QT4=	corelib
CONFIGURE_ARGS+=--enable-kde
#CONFIGURE_ENV+=KDE_CFLAGS="-I${KDE4_PREFIX}/include -I${QT_INCDIR} \
#	-I${LOCALBASE}/include" KDE_LIBS="-L${KDE4_PREFIX}/lib"
CPPFLAGS+=	-I${KDE4_PREFIX}/include
LDFLAGS+=	-L${KDE4_PREFIX}/lib
.else
CONFIGURE_ARGS+=--disable-kde
.endif

.if ${PORT_OPTIONS:MKAB}
CONFIGURE_ARGS+=--enable-kab
USE_KDE4+=	pimlibs
.else
CONFIGURE_ARGS+=--disable-kab
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=--enable-gstreamer
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MXCAP}
CONFIGURE_ARGS+=--enable-xcap
LIB_DEPENDS+=	libsoup-2.4.so:devel/libsoup
.else
CONFIGURE_ARGS+=--disable-xcap
.endif

.if ${PORT_OPTIONS:MLOUDMOUTH}
CONFIGURE_ARGS+=--enable-loudmouth
LIB_DEPENDS+=	libloudmouth-1.so:net-im/loudmouth
.else
CONFIGURE_ARGS+=--disable-loudmouth
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
LIB_DEPENDS+=	libsasl2.so:security/cyrus-sasl2
CONFIGURE_ARGS+=--enable-ldap --with-ldap-dir="${LOCALBASE}" --with-libsasl2-dir="${LOCALBASE}"
PLIST_SUB+=	LDAP=""
WITH_PLUGINS=	1
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(WITH_PLUGINS)
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:devel/libnotify
CONFIGURE_ARGS+=--enable-notify
PLIST_SUB+=	NOTIFY=""
WITH_PLUGINS=	1
.else
CONFIGURE_ARGS+=--disable-notify
PLIST_SUB+=	NOTIFY="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-1.so:devel/dbus
CONFIGURE_ARGS+=--enable-dbus --enable-dbus-service
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus --disable-dbus-service
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
GCONF_SCHEMAS=	ekiga.schemas
PLIST_SUB+=	GCONF="@comment "
.else
CONFIGURE_ARGS+=--disable-gconf
PLIST_SUB+=	GCONF=""
.endif

.if ${PORT_OPTIONS:MEVOLUTION}
USE_GNOME+=	evolutiondataserver3
LIB_DEPENDS+=	libgcr-3.so:security/gcr
CONFIGURE_ARGS+=--enable-eds
PLIST_SUB+=	EVOLUTION=""
WITH_PLUGINS=	1
.else
CONFIGURE_ARGS+=--disable-eds
PLIST_SUB+=	EVOLUTION="@comment "
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=--enable-avahi
LIB_DEPENDS+=	libavahi-client.so:net/avahi-app
PLIST_SUB+=	AVAHI=""
WITH_PLUGINS=	1
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

.if ${PORT_OPTIONS:MGNOMEHELP}
INSTALLS_OMF=	yes
PLIST_SUB+=	GNOMEHELP=""
USE_GNOME+=	gnomedocutils
.else
CONFIGURE_ARGS+=--disable-gdu
PLIST_SUB+=	GNOMEHELP="@comment "
.endif

.include <bsd.port.mk>
