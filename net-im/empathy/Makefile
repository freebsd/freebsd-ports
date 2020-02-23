# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	empathy
PORTVERSION=	3.12.14
PORTREVISION=	3
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		ca_root_nss>=0:security/ca_root_nss \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		geoclue>=0:net/geoclue \
		itstool:textproc/itstool \
		mc-tool:net-im/telepathy-mission-control
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libjson-glib-1.0.so:devel/json-glib \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libgeocode-glib.so:net/geocode-glib \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libp11-kit.so:security/p11-kit \
		libsecret-1.so:security/libsecret \
		libgee-0.8.so:devel/libgee \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpulse.so:audio/pulseaudio \
		libtelepathy.so:net-im/libtelepathy \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libfarstream-0.2.so:net-im/farstream \
		libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libfolks-telepathy.so:net-im/folks \
		libnotify.so:devel/libnotify \
		libgcr-3.so:security/gcr \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		ca_root_nss>=0:security/ca_root_nss \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		geoclue>=0:net/geoclue \
		mc-tool:net-im/telepathy-mission-control

USES=		compiler:c11 gettext gl gmake gnome libtool localbase pathfix \
		pkgconfig python:2.7 tar:xz xorg
USE_GNOME=	cairo evolutiondataserver3 intlhack
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USE_GL=		egl
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-Werror \
		--enable-goa \
		--disable-ubuntu-online-accounts \
		--disable-gudev \
		--enable-gst-1.0=yes \
		--enable-location=yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml \
		org.gnome.telepathy-account-widgets.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JABBER IRC SALUT HAZE MAP CHEESE
OPTIONS_DEFAULT=JABBER IRC SALUT      MAP

JABBER_DESC=	Enable jabber (XMPP) client support
JABBER_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-gabble:net-im/telepathy-gabble

IRC_DESC=	Enable IRC client support
IRC_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-idle:net-im/telepathy-idle

SALUT_DESC=	Enable link-local (serverless) XMPP support
SALUT_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-salut:net-im/telepathy-salut

HAZE_DESC=	Enable libpurple protocol integration
HAZE_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-haze:net-im/telepathy-haze

MAP_DESC=	Enable graphical map support
MAP_USE=		GL=gl
MAP_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain
MAP_CONFIGURE_ENABLE=	map

CHEESE_DESC=	Enable cheese camera support
CHEESE_BUILD_DEPENDS=	cheese>=0:multimedia/cheese
CHEESE_RUN_DEPENDS=	cheese>=0:multimedia/cheese
CHEESE_CONFIGURE_WITH=	cheese

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
