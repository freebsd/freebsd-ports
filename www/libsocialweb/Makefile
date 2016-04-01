# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsocialweb
PORTVERSION=	0.25.21
PORTREVISION=	3
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Personal social data server

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	librest-0.7.so:devel/librest \
		libgnome-keyring.so:security/libgnome-keyring \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gconf2 glib20 intlhack introspection:build \
		libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-vala-bindings
# review if we want all the services enabled, because of not completely
# safe public API security wise?
CONFIGURE_ARGS+=--enable-all-services
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
