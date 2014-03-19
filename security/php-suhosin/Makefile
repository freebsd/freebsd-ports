# Created by: ale
# $FreeBSD$

PORTNAME=	suhosin
PORTVERSION=	0.9.33
CATEGORIES=	security
MASTER_SITES=	http://download.suhosin.org/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PHP extension that implements high-level protections

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5 55

CONFIGURE_ARGS=	--enable-suhosin

NO_STAGE=	yes
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/suhosin.ini ${EXAMPLESDIR}

.include <bsd.port.mk>
