# Ports collection makefile for:	pecl-http
# Date created:		23 July 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	http
PORTVERSION=	1.6.4
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	pecl_${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	Extended HTTP Support

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-http-curl-requests \
			--with-http-zlib-compression \
			--with-http-magic-mime

.include <bsd.port.mk>
