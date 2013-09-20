# Created by: Max Baryshnikov <mephius@gmail.com>
# $FreeBSD$

PORTNAME=	sphinx
DISTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mephius@gmail.com
COMMENT=	Sphinx search engine php client

LIB_DEPENDS=	sphinxclient.0:${PORTSDIR}/textproc/libsphinxclient

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	sphinx

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CFLAGS=		-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
