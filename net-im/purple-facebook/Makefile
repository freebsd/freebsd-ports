# $FreeBSD$

PORTNAME=	purple-facebook
PORTVERSION=	0.9.6
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/dequis/purple-facebook/releases/download/v${PORTVERSION}/

DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Facebook plugin for libpurple

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpurple.so:net-im/libpurple \
		libjson-glib-1.0.so:devel/json-glib

USES=		autoreconf gnome libtool pkgconfig
PLIST_FILES=	lib/purple-2/libfacebook.so
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
