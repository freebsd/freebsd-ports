# New ports collection makefile for: pgdriver
# Date created: 	12 March 2001
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	pgdriver
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://openacs.org/sdm/download-package/2/38/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A driver for AOLserver to PostgreSQL connectivity

BUILD_DEPENDS=	${LOCALBASE}/aolserver/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS=	${BUILD_DEPENDS}

BROKEN=		Size mismatch
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_PGSQL=	yes

MAKEFILE=	makefile
MAKE_ENV+=	PREFIX=${PREFIX}
PLIST_FILES=	aolserver/bin/postgres.so

.include <bsd.port.mk>
