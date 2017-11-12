# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc pear

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Bindings for Chromium Compact Language Detector

LICENSE=	BSD2CLAUSE

DEPRECATED=	Depends on expired devel/cld
EXPIRATION_DATE=2017-12-12

LIB_DEPENDS=	libcld.so:devel/cld

CONFIGURE_ARGS=	--enable-cld --with-libcld-dir=${LOCALBASE}/lib
USES=		php:pecl
IGNORE_WITH_PHP=	70

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/php/${PHP_EXT_DIR}/cld.so

.include <bsd.port.mk>
