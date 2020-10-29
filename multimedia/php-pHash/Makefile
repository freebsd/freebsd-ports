# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	pHash
PORTVERSION=	0.9.6
PORTREVISION=	5
CATEGORIES=	multimedia devel
MASTER_SITES=	http://phash.org/releases/ \
		http://www.cyberbotx.com/pHash/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	PHP extension for the pHash perceptual hash library

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpHash.so:multimedia/pHash

USES=		compiler:c++11-lang php:ext
# Does not build for PHP 8.0
IGNORE_WITH_PHP=	80

WRKSRC_SUBDIR=	bindings/php

# The tarball contains stale pre-built files that interfere with building this
# ourselves.
post-configure:
	@(cd ${WRKSRC} && ${MAKE_CMD} clean)

.include <bsd.port.mk>
