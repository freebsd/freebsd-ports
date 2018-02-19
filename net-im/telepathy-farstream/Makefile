# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-farstream
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farstream Connection Manager for Telepathy Framework

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libfarstream-0.2.so:net-im/farstream

USES=		gmake libtool pathfix pkgconfig python:2.7
USE_GNOME=	glib20 libxslt:build introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
