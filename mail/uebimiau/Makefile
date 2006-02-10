# New ports collection makefile for:	uebimiau
# Date created: 			13 August 2003
# Whom: 				Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	uebimiau
DISTVERSION=	2.7.9
CATEGORIES=	mail www
MASTER_SITES=	http://www.uebimiau.org/downloads/ \
		http://www.freebsdbrasil.com.br/~jmelo/ \
		http://freebsd.jose.idv.tw/download/ \
		http://my.so-net.net.tw/jliang/uebimiau/
DISTNAME=	${PORTNAME}-${DISTVERSION}-any

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	UebiMiau is a simple yet efficient WebMail written in PHP

WRKSRC=		${WRKDIR}/webmail

USE_ZIP=	yes
USE_PHP=	pcre
WANT_PHP_MOD=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

post-extract:
	@${RM} -f ${WRKSRC}/themes/aleborgXP/C?pia\ de\ messagelist.htm

do-install:
	${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	${CP} -vR ${WRKSRC}/* ${PREFIX}/www/data/${PORTNAME}
	${CHOWN} -R www:www ${PREFIX}/www/data/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
