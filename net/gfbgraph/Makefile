# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gfbgraph
PORTVERSION=	0.2.3
CATEGORIES=	net www
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library for Facebook Graph API

BUILD_DEPENDS=	gtkdoc-rebase:textproc/gtk-doc
LIB_DEPENDS=	librest-0.7.so:devel/librest \
		libgoa-1.0.so:net/gnome-online-accounts \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e 's|/doc/libgfbgraph|/share/doc/libgfbgraph|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
