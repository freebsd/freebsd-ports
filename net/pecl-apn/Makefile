# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	apn
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	net pear

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension to interact with Apple Push Notification Service

LICENSE=	PHP301

LIB_DEPENDS=	libcapn.so:net/libcapn

USES=		php:pecl ssl:build,run
CONFIGURE_ARGS=	--with-apn=${LOCALBASE}
CFLAGS+=	-I${OPENSSLINC}
IGNORE_WITH_PHP=	70 71 72

.include <bsd.port.mk>
