# New ports collection makefile for:	mod_auth_pam
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_mp3
PORTVERSION=	0.6
CATEGORIES=	www
MASTER_SITES=	http://www.tangent.org/mod_mp3/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_mp3.c

do-install:
	${APXS} -i -A -n mp3 ${WRKSRC}/mod_mp3.so

.include <bsd.port.mk>
