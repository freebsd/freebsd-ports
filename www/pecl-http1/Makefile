# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	http
PORTVERSION=	1.7.6
PORTREVISION=	1
CATEGORIES=	www
PKGNAMESUFFIX=	1
DISTNAME=	pecl_http-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extended HTTP Support

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73
CONFLICTS=	pecl-http-*

CONFIGURE_ARGS+=	--with-http-curl-requests \
			--with-http-zlib-compression \
			--with-http-magic-mime

.include <bsd.port.mk>
