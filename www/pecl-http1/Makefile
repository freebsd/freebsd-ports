# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	http
PORTVERSION=	1.7.6
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	1
DISTNAME=	pecl_http-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Extended HTTP Support

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70
CONFLICTS=	pecl-http-*

CONFIGURE_ARGS+=	--with-http-curl-requests \
			--with-http-zlib-compression \
			--with-http-magic-mime

.include <bsd.port.mk>
