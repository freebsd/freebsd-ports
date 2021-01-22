# $FreeBSD$

PORTNAME=	snuffleupagus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Security module for PHP 7+

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		localbase:ldflags php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	jvoisin
USE_PHP=	hash:build session:build

CONFIGURE_ARGS=	--enable-snuffleupagus

TEST_TARGET=	test

# Fix build with clang11
CFLAGS+=	-fcommon

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
