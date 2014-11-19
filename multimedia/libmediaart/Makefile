# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/libmediaart/Makefile 19950 2014-10-15 06:29:10Z gusi $

PORTNAME=	libmediaart
PORTVERSION=	0.7.0
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		vala>=0:${PORTSDIR}/lang/vala

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
