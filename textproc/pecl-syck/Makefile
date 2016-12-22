# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	syck
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PECL extension which facilitates YAML parsing

LICENSE=	PHP301

BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:textproc/syck

USES=		php:ext tar:tgz
USE_PHP=	spl:build hash:build
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-syck

.include <bsd.port.mk>
