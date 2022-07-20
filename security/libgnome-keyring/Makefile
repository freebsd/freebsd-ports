PORTNAME=	libgnome-keyring
PORTVERSION=	3.12.0
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgcrypt.so:security/libgcrypt

USE_GNOME=	glib20 gnomeprefix intlhack \
		introspection:build
USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-vala
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gnome-keyring

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
