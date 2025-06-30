PORTNAME=	gnome-control-center
PORTVERSION=	47.6
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for the GNOME desktop
WWW=		https://apps.gnome.org/Settings/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		tecla>0:x11/tecla
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libcolord-gtk4.so:graphics/colord-gtk \
		libcolord.so:graphics/colord \
		libcups.so:print/cups \
		libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgtop-2.0.so:devel/libgtop \
		libibus-1.0.so:textproc/ibus \
		libpolkit-gobject-1.so:sysutils/polkit \
		libpulse.so:audio/pulseaudio \
		libpwquality.so:security/libpwquality \
		libsecret-1.so:security/libsecret \
		libudisks2.so:sysutils/libudisks \
		libupower-glib.so:sysutils/upower \
		libgudev-1.0.so:devel/libgudev \
		libgcr-4.so:security/gcr \
		libgnutls.so:security/gnutls
RUN_DEPENDS=	cantarell-fonts>=0:x11-fonts/cantarell-fonts \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		gnome-backgrounds>0:x11-themes/gnome-backgrounds \
		tecla>0:x11/tecla \
		cups-pk-helper>0:print/cups-pk-helper

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:build samba:lib tar:xz xorg
USE_GNOME=	cairo gdkpixbufextra gnomedesktop4 glib20 gtk40 gsound \
		libadwaita libxml2
USE_XORG=	x11 xi
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Dlocation-services=disabled \
		-Dsnap=false \
		-Dtests=false

GLIB_SCHEMAS=	org.gnome.Settings.gschema.xml

OPTIONS_SUB=	yes

OPTIONS_DEFINE=		WAYLAND
OPTIONS_DEFAULT=	WAYLAND

WAYLAND_MESON_TRUE=	wayland

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|' \
		${WRKSRC}/panels/printers/pp-host.c

.include <bsd.port.mk>
