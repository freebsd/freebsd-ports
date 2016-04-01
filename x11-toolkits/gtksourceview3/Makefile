# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtksourceview
PORTVERSION=	3.18.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget

USES=		tar:xz

PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	vala:lang/vala

USES+=		gettext gmake gnome libtool pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build \
		libxml2 referencehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no \
		--enable-glade-catalog=no \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

.include <bsd.port.mk>

.endif
