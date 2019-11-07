# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-settings-daemon
PORTVERSION=	1.22.0
PORTREVISION=	1
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE settings daemon

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxklavier.so:x11/libxklavier \
		libnss3.so:security/nss \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpolkit-gobject-1.so:sysutils/polkit \
		libstartup-notification-1.so:x11/startup-notification \
		libcanberra-gtk.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libnspr4.so:devel/nspr \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	xrdb:x11/xrdb

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase mate pathfix \
		pkgconfig tar:xz xorg
USE_MATE=	desktop libmatekbd mixer
USE_XORG=	ice sm x11 xext xi
USE_GNOME=	cairo dconf gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--disable-static \
		--disable-rfkill

INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.SettingsDaemon.plugins.a11y-keyboard.gschema.xml \
		org.mate.SettingsDaemon.plugins.a11y-settings.gschema.xml \
		org.mate.SettingsDaemon.plugins.background.gschema.xml \
		org.mate.SettingsDaemon.plugins.clipboard.gschema.xml \
		org.mate.SettingsDaemon.plugins.datetime.gschema.xml \
		org.mate.SettingsDaemon.plugins.gschema.xml \
		org.mate.SettingsDaemon.plugins.housekeeping.gschema.xml \
		org.mate.SettingsDaemon.plugins.keybindings.gschema.xml \
		org.mate.SettingsDaemon.plugins.keyboard.gschema.xml \
		org.mate.SettingsDaemon.plugins.media-keys.gschema.xml \
		org.mate.SettingsDaemon.plugins.mouse.gschema.xml \
		org.mate.SettingsDaemon.plugins.mpris.gschema.xml \
		org.mate.SettingsDaemon.plugins.rfkill.gschema.xml \
		org.mate.SettingsDaemon.plugins.smartcard.gschema.xml \
		org.mate.SettingsDaemon.plugins.sound.gschema.xml \
		org.mate.SettingsDaemon.plugins.typing-break.gschema.xml \
		org.mate.SettingsDaemon.plugins.xrandr.gschema.xml \
		org.mate.SettingsDaemon.plugins.xrdb.gschema.xml \
		org.mate.SettingsDaemon.plugins.xsettings.gschema.xml \
		org.mate.applications-at.gschema.xml \
		org.mate.font-rendering.gschema.xml \
		org.mate.peripherals-smartcard.gschema.xml \
		org.mate.peripherals-touchpad.gschema.xml

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_SUB=	yes

PULSEAUDIO_CONFIGURE_ENABLE=	pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

.include <bsd.port.mk>
