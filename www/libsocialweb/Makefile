# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/www/libsocialweb/Makefile 19207 2014-03-20 08:36:54Z gusi $

PORTNAME=	libsocialweb
PORTVERSION=	0.25.21
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Personal social data server.

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	librest-0.7.so:${PORTSDIR}/devel/librest \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USE_GNOME=	gconf2 glib20 gnomehier intlhack introspection:build \
		libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig tar:xz
CONFIGURE_ARGS=	--enable-vala-bindings
# review if we want all the services enabled, because of not completely
# safe public API security wise?
CONFIGURE_ARGS+=--enable-all-services 

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsocialweb.so.*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsocialweb-*.so.*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsocialweb/services/lib*so*

.include <bsd.port.mk>
