# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/net/gfbgraph/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	gfbgraph
PORTVERSION=	0.2.2
CATEGORIES=	net www
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library for Facebook Graph API

BUILD_DEPENDS=	gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	librest-0.7.so:${PORTSDIR}/devel/librest \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
