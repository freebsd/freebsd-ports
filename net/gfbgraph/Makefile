PORTNAME=	gfbgraph
DISTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library for Facebook Graph API
WWW=		https://git.gnome.org/browse/libgfbgraph

BUILD_DEPENDS=	gtkdoc-rebase:textproc/gtk-doc
LIB_DEPENDS=	librest-0.7.so:devel/librest \
		libgoa-1.0.so:net/gnome-online-accounts \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		autoreconf cpe gettext gmake gnome libtool localbase:ldflags pathfix \
		pkgconfig tar:xz
CPE_VENDOR=	gnome
CPE_PRODUCT=	lib${PORTNAME}
USE_GNOME=	glib20 intlhack introspection:build libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtk-doc

INSTALL_TARGET=	install install-strip

.include <bsd.port.mk>
