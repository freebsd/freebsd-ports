# New ports collection makefile for:	uebimiau
# Date created: 			13 August 2003
# Whom: 				Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	uebimiau
PORTVERSION=	2.7.2
CATEGORIES=	mail www
MASTER_SITES=	http://www.uebimiau.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-any

MAINTAINER=	francisco@gomezmarin.com
COMMENT=	UebiMiau is a simple yet efficient WebMail written in PHP

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data/uebimiau
	${CHOWN} -R www:www ${PREFIX}/www/data/uebimiau

.include <bsd.port.mk>
