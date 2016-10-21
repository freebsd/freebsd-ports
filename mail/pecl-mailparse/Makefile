# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	mailparse
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	PECL extension to create and decode MIME messages

LICENSE=	PHP202

PORTSCOUT=	limit:^2.*

USES=		php:ext tar:tgz
USE_PHP=	mbstring:build
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
