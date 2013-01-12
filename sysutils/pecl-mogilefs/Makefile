# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	mogilefs
PORTVERSION=	0.9.2
CATEGORIES=	sysutils pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PHP client library to communicate with the MogileFS storage

LICENSE=	BSD

LIB_DEPENDS=	neon.27:${PORTSDIR}/www/neon29

IGNORE_WITH_PHP=4

USE_PHP=	yes
USE_PHP_BUILD=	spl
USE_PHPIZE=	yes
USE_PHPEXT=	yes

post-extract:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
