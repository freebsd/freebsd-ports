# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	syck
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	textproc pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PECL extension which facilitates YAML parsing

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:textproc/syck

USES=		php:pecl
USE_PHP=	spl:build hash:build
IGNORE_WITH_PHP=	71 72 73

CONFIGURE_ARGS=	--enable-syck

.include <bsd.port.mk>
