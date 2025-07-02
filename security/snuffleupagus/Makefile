PORTNAME=	snuffleupagus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	security
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	b005df2.patch:-p2

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
IGNORE_WITH_PHP=	84 85

CONFIGURE_ARGS=	--enable-snuffleupagus

TEST_TARGET=	test

# Fix build with clang11
CFLAGS+=	-fcommon

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
