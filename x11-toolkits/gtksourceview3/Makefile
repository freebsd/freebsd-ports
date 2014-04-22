# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtksourceview3/Makefile,v 1.21 2012/05/31 11:57:38 kwm Exp $

PORTNAME=	gtksourceview
PORTVERSION=	3.4.2
PORTREVISION?=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A text widget that adds syntax highlighting to the GtkTextView widget

USES=		tar:xz

.if !defined(REFERENCE_PORT)

USE_LDCONFIG=	yes
USES+=		libtool pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gtk30 libxml2 intlhack referencehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no --enable-glade-catalog=no \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

.include <bsd.port.mk>

.endif
