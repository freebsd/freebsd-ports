# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/net/gfbgraph/Makefile 19571 2014-04-25 18:12:46Z kwm $

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

USE_GNOME=	glib20 intlhack introspection:build
USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgfbgraph-0.2.so.0 

.include <bsd.port.mk>
