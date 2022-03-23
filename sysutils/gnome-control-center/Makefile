# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-control-center
PORTVERSION=	42.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas # #		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libadwaita-1.so:x11-toolkits/libadwaita \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libcolord-gtk.so:graphics/colord-gtk \
		libcolord.so:graphics/colord \
		libcups.so:print/cups \
		libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgrilo-0.3.so:net/grilo \
		libgtop-2.0.so:devel/libgtop \
		libhandy-1.so:x11-toolkits/libhandy \
		libibus-1.0.so:textproc/ibus \
		libpolkit-gobject-1.so:sysutils/polkit \
		libpulse.so:audio/pulseaudio \
		libpwquality.so:security/libpwquality \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libudisks2.so:sysutils/libudisks \
		libupower-glib.so:sysutils/upower
RUN_DEPENDS=	cantarell-fonts>=0:x11-fonts/cantarell-fonts \
		gcm-import:graphics/gnome-color-manager \
		gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:3.6+,build samba:lib tar:xz xorg
USE_GNOME=	cairo gnomedesktop3 gsound libxml2
USE_XORG=	x11 xi
#USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Settings.gschema.xml

OPTIONS_SUB=	yes

OPTIONS_DEFINE=		WAYLAND
OPTIONS_DEFAULT=	WAYLAND

WAYLAND_MESON_TRUE=	wayland
WAYLAND_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

.include <bsd.port.pre.mk>

# FreeBSD base gained an os-release in r354922, but that does not exist
# always (see Synth bug 191, or PR 255354). Be a little more forgiving:
# assume sufficiently recent base "will have it", and check otherwise
# because 12.2 does, others like 12.1 do not have it.
.if !exists(/etc/rc.d/os-release) && (${OSVERSION} < 1300060)
RUN_DEPENDS+=	etc_os-release>0:sysutils/etc_os-release
post-patch:
	@${REINPLACE_CMD}  -e 's|/etc/os-release|${LOCALBASE}/etc/os-release|g' \
		${WRKSRC}/panels/common/cc-os-release.c
.endif

.include <bsd.port.post.mk>
