# $FreeBSD$

PORTNAME=	snuffleupagus
DISTVERSIONPREFIX=v
DISTVERSION=	0.4.1
CATEGORIES=	security
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Security module for PHP 7+

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/../LICENSE

IGNORE_WITH_PHP=	56

LIB_DEPENDS=	libpcre.so:devel/pcre

TEST_TARGET=	test

WRKSRC_SUBDIR=	src

USES=		localbase:ldflags php:ext
USE_PHP=	hash:build session:build

USE_GITHUB=	yes
GH_ACCOUNT=	nbs-system

CONFIGURE_ARGS=	--enable-snuffleupagus

.include <bsd.port.mk>
