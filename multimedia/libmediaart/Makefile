# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libmediaart
PORTVERSION=	1.9.0
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc \
		vala>=0:lang/vala

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gdkpixbuf2 glib20 introspection
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--enable-gtk-doc \
		--enable-introspection \
		--enable-vala
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
