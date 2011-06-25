# New ports collection makefile for:    pecl-sphinx
# Date created:         2011-06-6
# Whom:                 Max Baryshnikov <mephius@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sphinx
DISTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mephius@gmail.com
COMMENT=	Sphinx search engine php client

LIB_DEPENDS=	sphinxclient.0:${PORTSDIR}/textproc/libsphinxclient

USE_PHP=	yes
IGNORE_WITH_PHP=4
USE_PHPEXT=	yes
PHP_MODNAME=	sphinx

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CFLAGS=		-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
