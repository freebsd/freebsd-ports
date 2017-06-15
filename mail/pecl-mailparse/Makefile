# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	mailparse
PORTVERSION=	3.0.2
CATEGORIES=	mail www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	PECL extension to create and decode MIME messages

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:ext tar:tgz
USE_PHP=	mbstring:build
IGNORE_WITH_PHP=	56

.include <bsd.port.mk>
