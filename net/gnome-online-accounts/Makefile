# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.16.5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interface provider to access the user's online accounts

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libwebkit2gtk-4.0.so:${PORTSDIR}/www/webkit2-gtk3 \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		librest-0.7.so:${PORTSDIR}/devel/librest

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack introspection:build libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.online-accounts.gschema.xml

# for webkit2-gtk3
USES+=		compiler:c++11-lib

.include <bsd.port.mk>
