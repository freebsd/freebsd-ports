# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	1.1.0
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	YAML-1.1 parser and emitter

LIB_DEPENDS=	yaml:${PORTSDIR}/textproc/libyaml

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
