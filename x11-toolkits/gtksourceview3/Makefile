# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gtksourceview3/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	gtksourceview
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget

.if !defined(REFERENCE_PORT)

USES+=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build \
		libxml2 referencehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
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
