PORTNAME=	purple-facebook
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/dequis/purple-facebook/releases/download/v${PORTVERSION}/

DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Facebook plugin for libpurple
WWW=		https://github.com/dequis/purple-facebook

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpurple.so:net-im/libpurple \
		libjson-glib-1.0.so:devel/json-glib

USES=		autoreconf gnome libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/purple-2/libfacebook.so

.include <bsd.port.mk>
