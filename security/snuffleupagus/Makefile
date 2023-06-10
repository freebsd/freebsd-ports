PORTNAME=	snuffleupagus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	security
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Security module for PHP
WWW=		https://snuffleupagus.readthedocs.io/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		localbase:ldflags php:build,ext
USE_GITHUB=	yes
GH_ACCOUNT=	jvoisin
USE_PHP=	session:build
IGNORE_WITH_PHP=	82 83

CONFIGURE_ARGS=	--enable-snuffleupagus

TEST_TARGET=	test

# Fix build with clang11
CFLAGS+=	-fcommon

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
