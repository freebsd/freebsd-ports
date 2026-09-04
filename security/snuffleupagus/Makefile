PORTNAME=	snuffleupagus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Security module for PHP
WWW=		https://snuffleupagus.readthedocs.io/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		localbase:ldflags php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	jvoisin
USE_PHP=	session:build

CONFIGURE_ARGS=	--enable-snuffleupagus

TEST_TARGET=	test

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
