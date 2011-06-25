# New ports collection makefile for:	pecl-yaz
# Date created:			9 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	1.0.14
PORTREVISION=	4
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	till@php.net
COMMENT=	A PECL extension that implements a Z39.50 client

LIB_DEPENDS=	yaz.4:${PORTSDIR}/net/yaz

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}

.include <bsd.port.pre.mk>

pre-configure:
	@if [ `${PKG_INFO} 'yaz>=4.1.6' > /dev/null 2>&1` ]; then \
		${REINPLACE_CMD} -e 's|YAZVERSION|YAZ_VERSION|g' \
				${WRKSRC}/configure; fi

.include <bsd.port.post.mk>
