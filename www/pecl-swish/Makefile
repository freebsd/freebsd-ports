# Created by: chinsan
# $FreeBSD$

PORTNAME=	swish
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Swish-e bindings for PHP

LICENSE=	PHP301

BUILD_DEPENDS=	swish-config:www/swish-e
RUN_DEPENDS:=	swish-config:www/swish-e

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-swish --with-swish=${LOCALBASE}/bin

.include <bsd.port.mk>
