# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	mailparse
PORTVERSION=	2.1.6
CATEGORIES=	mail www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension to create and decode MIME messages

LICENSE=	PHP202

BROKEN_powerpc64=	Does not build

USES=		php:ext tar:tgz
USE_PHP=	mbstring:build
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
