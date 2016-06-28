# Created by: Max Baryshnikov <mephius@gmail.com>
# $FreeBSD$

PORTNAME=	sphinx
DISTVERSION=	1.3.3
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	mephius@gmail.com
COMMENT=	Sphinx search engine php client

LICENSE=	PHP301

LIB_DEPENDS=	libsphinxclient.so:textproc/libsphinxclient

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
