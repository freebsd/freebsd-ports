PORTNAME=	gnome-settings-daemon
PORTVERSION=	42.2
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	03739474621e.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-settings-daemon/-/merge_requests/300

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME settings daemon
WWW=		https://www.gnome.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libcolord.so:graphics/colord \
		libcups.so:print/cups \
		libfontconfig.so:x11-fonts/fontconfig \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgweather-4.so:net/libgweather4 \
		liblcms2.so:graphics/lcms2 \
		libnotify.so:devel/libnotify \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpolkit-gobject-1.so:sysutils/polkit \
		libpulse.so:audio/pulseaudio \
		libupower-glib.so:sysutils/upower

PORTSCOUT=	limitw:1,even

USE_XORG=	x11 xext xi xtst
USE_GNOME=	cairo gnomedesktop3 gtk30
USES=		gettext gnome localbase:ldflags meson perl5 pkgconfig \
		python:build tar:xz xorg
USE_PERL5=	build
#		-Dnssdb_dir=${LOCALBASE}/share/certs/ca-root-nss.crt
MESON_ARGS=	-Dalsa=false \
		-Dcolord=false \
		-Dcups=true \
		-Dnetwork_manager=false \
		-Dnssdb_dir=${LOCALBASE}/share/certs/ \
		-Drfkill=false \
		-Dsmartcard=true \
		-Dsystemd=false \
		-Dwwan=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

# wayland doesn't build yet, undefined symbol
MESON_ARGS+=	-Dgudev=false \
		-Dwayland=false
#WAYLAND_MESON_TRUE=	wayland gudev
#WAYLAND_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev \
#			libwayland-client.so:graphics/wayland

GLIB_SCHEMAS=	org.gnome.settings-daemon.enums.xml \
		org.gnome.settings-daemon.peripherals.gschema.xml \
		org.gnome.settings-daemon.peripherals.wacom.gschema.xml \
		org.gnome.settings-daemon.plugins.color.gschema.xml \
		org.gnome.settings-daemon.plugins.gschema.xml \
		org.gnome.settings-daemon.plugins.housekeeping.gschema.xml \
		org.gnome.settings-daemon.plugins.media-keys.gschema.xml \
		org.gnome.settings-daemon.plugins.power.gschema.xml \
		org.gnome.settings-daemon.plugins.power.gschema.xml.override \
		org.gnome.settings-daemon.plugins.sharing.gschema.xml \
		org.gnome.settings-daemon.plugins.xsettings.gschema.xml

post-install:
	${INSTALL_DATA} ${FILESDIR}/org.gnome.settings-daemon.plugins.power.gschema.xml.override \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/

.include <bsd.port.mk>
