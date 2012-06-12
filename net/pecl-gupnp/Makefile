# New ports collection makefile for:	pecl-gupnp
# Date created:		2012-03-16
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp
PORTVERSION=	1.0.0
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GUPnP wrapper extension

LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp

USE_PHP=	yes
USE_PHPEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -ldl||g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
