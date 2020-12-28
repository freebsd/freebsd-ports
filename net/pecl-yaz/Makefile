# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaz
PORTVERSION=	1.2.1
CATEGORIES=	net pear

MAINTAINER=	fw@moov.de
COMMENT=	PECL extension that implements a Z39.50 client

LICENSE=	PHP301

DEPRECATED=	PHP 7.2 extension
EXPIRATION_DATE=        2020-12-31

LIB_DEPENDS=	libyaz.so:net/yaz

USES=		gnome php:pecl
USE_GNOME+=	libxslt
IGNORE_WITH_PHP=	73 74 80

CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}

.include <bsd.port.mk>
