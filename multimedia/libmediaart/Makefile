# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/libmediaart/Makefile 19806 2014-08-14 07:01:32Z gusi $

PORTNAME=	libmediaart
PORTVERSION=	0.5.0
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		vala>=0:${PORTSDIR}/lang/vala \
		vapigen:${PORTSDIR}/lang/vala-vapigen

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
