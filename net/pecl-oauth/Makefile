# New ports collection makefile for:	pecl-oauth
# Date created:			25 Nov 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oauth
PORTVERSION=	0.99.5
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Php Interface to the OAuth Protocol

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:${PORTSDIR}/ftp/curl

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
