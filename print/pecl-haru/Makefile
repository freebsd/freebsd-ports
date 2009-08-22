# New ports collection makefile for:	pecl-haru
# Date created:			20 Nov 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	haru
PORTVERSION=	1.0.0
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
#DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension to Haru PDF functions

BUILD_DEPENDS=	${LOCALBASE}/include/hpdf.h:${PORTSDIR}/print/libharu
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-haru=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
