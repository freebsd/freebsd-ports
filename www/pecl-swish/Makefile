# Created by: chinsan
# $FreeBSD$

PORTNAME=	swish
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Swish-e bindings for PHP

LICENSE=	PHP301

BUILD_DEPENDS=	swish-config:www/swish-e
RUN_DEPENDS:=	swish-config:www/swish-e

USES=		php:pecl
IGNORE_WITH_PHP=	70 71 72

CONFIGURE_ARGS=	--enable-swish --with-swish=${LOCALBASE}/bin

.include <bsd.port.mk>
