# New ports collection makefile for: nspostgres
# Date created: 	30 January 2001
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	nspostgres
PORTVERSION=	3.0
CATEGORIES=	www databases
MASTER_SITES=	ftp://ftp.aolserver.com/modules/nspostgres/
DISTNAME=	nspostgres3_0

MAINTAINER=	jkoshy@freebsd.org

RUN_DEPENDS=	${LOCALBASE}/aolserver/bin/nsd:${PORTSDIR}/www/aolserver \
		${LOCALBASE}/pgsql/bin/postmaster:${PORTSDIR}/databases/postgresql7

WRKSRC=		${WRKDIR}/nspostgres

USE_GMAKE=	yes
MAKE_ENV+=	POSTGRES=${PREFIX}/pgsql BUILDPREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspostgres.so ${PREFIX}/aolserver/bin

.include <bsd.port.mk>
