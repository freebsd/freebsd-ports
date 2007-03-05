# New ports collection makefile for:	suhosin
# Date created:			4 Sep 2006
# Whom:				ale
#
# $FreeBSD$
#

PORTNAME=	suhosin
PORTVERSION=	0.9.17
CATEGORIES=	security
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PHP extension that implements high-level protections

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-suhosin

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/suhosin.ini ${EXAMPLESDIR}

.include <bsd.port.mk>
