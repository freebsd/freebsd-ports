# New ports collection makefile for:	mod_limitipconn
# Date created:				18 April 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_limitipconn
PORTVERSION=	0.04
CATEGORIES=	www
MASTER_SITES=	http://dominia.org/djao/limit/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	Limit the number of simultaneous connections from a single client IP address

BUILD_DEPENDS?=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS?=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

do-install:
	${APXS} -i -A -n limitipconn ${WRKSRC}/mod_limitipconn.so

.include <bsd.port.mk>
