# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	apn
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	net pear

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension to interact with Apple Push Notification Service

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

LIB_DEPENDS=	libcapn.so:net/libcapn

USES=		php:pecl ssl:build,run
CONFIGURE_ARGS=	--with-apn=${LOCALBASE}
CFLAGS+=	-I${OPENSSLINC}
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
