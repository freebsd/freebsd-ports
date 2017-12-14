# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	solr
PORTVERSION=	2.4.0
CATEGORIES=	www

MAINTAINER=	gaod@hychen.org
COMMENT=	PHP extension for Apache Solr

LICENSE=	PHP301

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

USES=		php:pecl
USE_PHP=	json:build
IGNORE_WITH_PHP=	72

.include <bsd.port.mk>
