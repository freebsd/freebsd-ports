PORTNAME=	libzapojit
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GObject wrapper for the Skydrive and Hotmail API
WWW=		https://github.com/GNOME/libzapojit

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libjson-glib-1.0.so:devel/json-glib \
		librest-0.7.so:devel/librest

USES=		cpe gettext gmake gnome libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	gnomeprefix intltool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
