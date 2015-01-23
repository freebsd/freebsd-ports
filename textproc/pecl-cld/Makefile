# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	0.5.0
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Bindings for Chromium Compact Language Detector

LICENSE=	BSD2CLAUSE

BROKEN=		Missing headers with cld 20150113

LIB_DEPENDS=	libcld.so:${PORTSDIR}/devel/cld

CONFIGURE_ARGS=	--enable-cld --with-libcld-dir=${LOCALBASE}/lib
USES=		tar:tgz
USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/php/${PHP_EXT_DIR}/cld.so

.include <bsd.port.mk>
