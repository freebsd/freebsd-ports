# New ports collection makefile for:	suhosin
# Date created:			4 Sep 2006
# Whom:				ale
#
# $FreeBSD$
#

PORTNAME=	suhosin
PORTVERSION=	0.9.0
CATEGORIES=	security
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-200609031730
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PHP extension that implements high-level protections

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-suhosin

.include <bsd.port.mk>
