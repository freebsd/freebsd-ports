PORTNAME=	gnome-online-accounts
PORTVERSION=	3.54.4
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interface provider to access the user's online accounts
WWW=		https://gnome.pages.gitlab.gnome.org/gnome-online-accounts/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		librest-1.0.so:net/librest1 \
		libp11-kit.so:security/p11-kit \
		libdbus-1.so:devel/dbus

USES=		compiler:c++11-lib desktop-file-utils gettext gnome \
		localbase meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 gtk40 introspection:build libadwaita libxml2 \
		libxslt:build
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.online-accounts.gschema.xml

MESON_ARGS+=	-Dexchange=true \
		-Dkerberos=false \
		-Dwindows_live=true \
		-Dms_graph=false \
		-Ddocumentation=false

.include <bsd.port.mk>
