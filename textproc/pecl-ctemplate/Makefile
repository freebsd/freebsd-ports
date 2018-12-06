# Created by: vanilla
# $FreeBSD$

PORTNAME=	cTemplate
PORTVERSION=	1.14
CATEGORIES=	textproc pear
DISTVERSIONPREFIX=	v
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PECL extension for ctemplate library

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LIB_DEPENDS=	libctemplate.so:textproc/google-ctemplate

USES=		php:ext localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	vanillahsu
GH_PROJECT=	pecl-ctemplate
IGNORE_WITH_PHP=	71 72 73

CONFIGURE_ARGS=	--with-cTemplate=${LOCALBASE}

.include <bsd.port.mk>
