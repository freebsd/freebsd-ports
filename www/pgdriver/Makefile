# New ports collection makefile for: pgdriver
# Date created: 	12 March 2001
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	pgdriver
PORTVERSION=	1.1
CATEGORIES=	www databases
MASTER_SITES=	http://openacs.org/sdm/download-package/2/20/

MAINTAINER=	jkoshy@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/aolserver/bin/nsd:${PORTSDIR}/www/aolserver \
		${LOCALBASE}/pgsql/bin/postmaster:${PORTSDIR}/databases/postgresql7
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKEFILE=	makefile

.include <bsd.port.mk>
