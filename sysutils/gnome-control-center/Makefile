# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-control-center
PORTVERSION=	3.38.3
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas #\
#		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcups.so:print/cups \
		libpulse.so:audio/pulseaudio \
		libfontconfig.so:x11-fonts/fontconfig \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libupower-glib.so:sysutils/upower \
		libaccountsservice.so:sysutils/accountsservice \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libibus-1.0.so:textproc/ibus \
		libsoup-2.4.so:devel/libsoup \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpwquality.so:security/libpwquality \
		libgtop-2.0.so:devel/libgtop \
		libgrilo-0.3.so:net/grilo \
		libpolkit-gobject-1.so:sysutils/polkit \
		libhandy-1.so:x11-toolkits/libhandy \
		libudisks2.so:sysutils/libudisks \
		libsecret-1.so:security/libsecret \
		libepoxy.so:graphics/libepoxy
RUN_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		cantarell-fonts>=0:x11-fonts/cantarell-fonts \
		gcm-import:graphics/gnome-color-manager

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:3.6+,build samba:lib tar:xz xorg
USE_GNOME=	cairo gnomedesktop3 libxml2 gsound
USE_XORG=	x11 xi
#USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.ControlCenter.gschema.xml

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	WAYLAND CHEESE
OPTIONS_DEFAULT=WAYLAND CHEESE

CHEESE_DESC=	Cheese webcam support
CHEESE_LIB_DEPENDS=	libcheese.so:multimedia/cheese
CHEESE_MESON_TRUE=	cheese

WAYLAND_MESON_TRUE=	wayland
WAYLAND_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

# This can be removed after 11.x is no longer supported
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
LDFLAGS+=      -fuse-ld=lld
.endif

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
