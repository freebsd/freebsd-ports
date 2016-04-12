# Created by: chinsan
# $FreeBSD$

PORTNAME=	swish
PORTVERSION=	0.5.0
CATEGORIES=	www pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Swish-e bindings for PHP

LICENSE=	PHP301

BUILD_DEPENDS=	swish-config:www/swish-e
RUN_DEPENDS:=	swish-config:www/swish-e

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-swish --with-swish=${LOCALBASE}/bin

.include <bsd.port.mk>
