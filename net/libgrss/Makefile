PORTNAME=	libgrss
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for easy management of RSS/Atom/Pie feeds
WWW=		https://www.gnome.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

USES=		cpe gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	glib20 intlhack introspection:build libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
