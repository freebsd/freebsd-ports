# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-settings-daemon
PORTVERSION=	1.8.1
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE settings daemon

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libnss3.so:${PORTSDIR}/security/nss \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	desktop libmatekbd
USE_XORG=	xxf86misc
USE_GNOME=	dconf gnomehier gtk20 intlhack
USE_LDCONFIG=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--disable-static \
		--disable-pulse
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.SettingsDaemon.plugins.a11y-keyboard.gschema.xml \
		org.mate.SettingsDaemon.plugins.background.gschema.xml \
		org.mate.SettingsDaemon.plugins.clipboard.gschema.xml \
		org.mate.SettingsDaemon.plugins.datetime.gschema.xml \
		org.mate.SettingsDaemon.plugins.housekeeping.gschema.xml \
		org.mate.SettingsDaemon.plugins.keybindings.gschema.xml \
		org.mate.SettingsDaemon.plugins.keyboard.gschema.xml \
		org.mate.SettingsDaemon.plugins.media-keys.gschema.xml \
		org.mate.SettingsDaemon.plugins.mouse.gschema.xml \
		org.mate.SettingsDaemon.plugins.mpris.gschema.xml \
		org.mate.SettingsDaemon.plugins.smartcard.gschema.xml \
		org.mate.SettingsDaemon.plugins.sound.gschema.xml \
		org.mate.SettingsDaemon.plugins.typing-break.gschema.xml \
		org.mate.SettingsDaemon.plugins.xrandr.gschema.xml \
		org.mate.SettingsDaemon.plugins.xrdb.gschema.xml \
		org.mate.SettingsDaemon.plugins.xsettings.gschema.xml \
		org.mate.applications-at.gschema.xml \
		org.mate.font-rendering.gschema.xml \
		org.mate.keybindings.gschema.xml \
		org.mate.peripherals-smartcard.gschema.xml \
		org.mate.peripherals-touchpad.gschema.xml

.include <bsd.port.mk>
