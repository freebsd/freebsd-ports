# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-control-center
PORTVERSION=	3.18.2
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		docbook-xsl>=0:textproc/docbook-xsl \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libupower-glib.so:sysutils/upower \
		libaccountsservice.so:sysutils/accountsservice \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libibus-1.0.so:textproc/ibus \
		libgoa-1.0.so:net/gnome-online-accounts \
		libsocialweb.so:www/libsocialweb \
		libpwquality.so:security/libpwquality \
		libgtop-2.0.so:devel/libgtop \
		libdbus-glib-1.so:devel/dbus-glib \
		libgrilo-0.2.so:net/grilo \
		libpolkit-gobject-1.so:sysutils/polkit
RUN_DEPENDS=	gnome-eject:sysutils/gnome-mount \
		gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes \
		glxinfo:graphics/mesa-demos \
		apg:security/apg \
		gcm-calibrate:graphics/gnome-color-manager

CONFLICTS=	gnome-media-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 intltool libxml2
USE_XORG=	xscrnsaver x11 xxf86misc kbproto xi
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
CUPS_DESC=	Cups (printing) support
CHEESE_DESC=	Cheese webcam support

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE
CUPS_LIB_DEPENDS=	libcups.so:print/cups \
			libsmbclient.so:net/samba-libsmbclient
CUPS_CONFIGURE_ENABLE=	cups
CHEESE_LIB_DEPENDS=	libcheese.so:multimedia/cheese
CHEESE_CONFIGURE_WITH=	cheese

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|datetime wacom|datetime|g' \
		${WRKSRC}/panels/Makefile.in

.include <bsd.port.mk>
