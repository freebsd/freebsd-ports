# New ports collection makefile for:	mod_realip
# Date created:				11 July 2005
# Whom:					glebius
#
# $FreeBSD$
#

PORTNAME=	mod_realip
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/mod_realip/

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Apache module to fix IP addresses in proxied requests

USE_APACHE=	yes
MAKE_ARGS+=	APXS="${APXS}"

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c ${WRKSRC}/mod_realip.c

do-install:
	${APXS} -i -A -n realip ${WRKSRC}/mod_realip.so

.include <bsd.port.mk>
