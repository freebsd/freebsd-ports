# New ports collection makefile for:	uebimiau
# Date created: 			13 August 2003
# Whom: 				Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	uebimiau
DISTVERSION=	2.7.8-RC1
CATEGORIES=	mail www
MASTER_SITES=	http://www.uebimiau.org/downloads/
DISTNAME=	${PORTNAME}-${DISTVERSION}-any

MAINTAINER=	francisco@gomezmarin.com
COMMENT=	UebiMiau is a simple yet efficient WebMail written in PHP

USE_PHP=	pcre
WANT_PHP_MOD=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data/${PORTNAME}
	${CHOWN} -R www:www ${PREFIX}/www/data/${PORTNAME}

.include <bsd.port.mk>
