PORTNAME=	purple-plugin-pack
PORTVERSION=	2.8.0
CATEGORIES=	net-im
MASTER_SITES=	https://dl.bintray.com/pidgin/releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of libpurple plugins
WWW=		https://keep.imfreedom.org/pidgin/purple-plugin-pack

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pidgin>0:net-im/pidgin
RUN_DEPENDS=	pidgin>0:net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		gettext meson pkgconfig tar:xz

.include <bsd.port.mk>
