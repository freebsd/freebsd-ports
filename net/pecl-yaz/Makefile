# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaz
PORTVERSION=	1.0.14
PORTREVISION=	5
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PECL extension that implements a Z39.50 client

LIB_DEPENDS=	yaz:${PORTSDIR}/net/yaz

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-configure:
	@if [ `${PKG_INFO} 'yaz>=4.1.6' > /dev/null 2>&1` ]; then \
		${REINPLACE_CMD} -e 's|YAZVERSION|YAZ_VERSION|g' \
				${WRKSRC}/configure; fi

.include <bsd.port.post.mk>
