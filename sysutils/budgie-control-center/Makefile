PORTNAME=	budgie-control-center
DISTVERSION=	1.4.1
CATEGORIES=	sysutils budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Control center for the Budgie desktop
WWW=		https://github.com/BuddiesOfBudgie/budgie-control-center

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy \
		libaccountsservice.so:sysutils/accountsservice \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpulse.so:audio/pulseaudio \
		libupower-glib.so:sysutils/upower \
		libepoxy.so:graphics/libepoxy \
		libgcr-base-3.so:security/gcr3 \
		libgudev-1.0.so:devel/libgudev \
		libpwquality.so:security/libpwquality \
		libpolkit-gobject-1.so:sysutils/polkit \
		libcups.so:print/cups \
		libibus-1.0.so:textproc/ibus \
		libudisks2.so:sysutils/libudisks \
		libgtop-2.0.so:devel/libgtop \
		libfontconfig.so:x11-fonts/fontconfig \
		libsecret-1.so:security/libsecret \
		libgnutls.so:security/gnutls
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		budgie compiler:c++11-lib gettext-tools gnome meson \
		localbase:ldflags pkgconfig samba:lib tar:xz xorg
USE_GNOME=	cairo gdkpixbuf glib20 gnomedesktop3 gtk30 gsound libxml2
USE_XORG=	x11 xi

MESON_ARGS=	-Dcheese=false

GLIB_SCHEMAS=	org.buddiesofbudgie.ControlCenter.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|' \
		${WRKSRC}/panels/printers/pp-host.c

.include <bsd.port.mk>
