# New ports collection makefile for:	mod_hosts_access
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_hosts_access
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.klomp.org/mod_hosts_access/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that makes Apache respect hosts.allow and hosts.deny

USE_APACHE=	yes
APXS_FLAGS?=	-S LDFLAGS_SHLIB="-shared -lwrap"

do-build:
	@cd ${WRKSRC} && ${APXS} ${APXS_FLAGS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/mod_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
