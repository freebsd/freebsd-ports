# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	2.0.0
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	YAML-1.1 parser and emitter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56

.include <bsd.port.mk>
