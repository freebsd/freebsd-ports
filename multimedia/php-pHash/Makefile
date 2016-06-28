# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	pHash
PORTVERSION=	0.9.6
CATEGORIES=	multimedia devel
MASTER_SITES=	http://phash.org/releases/ \
		http://www.cyberbotx.com/pHash/
PKGNAMEPREFIX=	php-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	PHP extension for the pHash perceptual hash library

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpHash.so:multimedia/pHash

USES=		php:ext

WRKSRC_SUBDIR=	bindings/php

# The tarball contains stale pre-built files that interfere with building this
# ourselves.
post-configure:
	@(cd ${WRKSRC} && ${MAKE_CMD} clean)

.include <bsd.port.mk>
