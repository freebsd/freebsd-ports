# New ports collection makefile for: nspostgres
# Date created: 	30 January 2001
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	nspostgres
PORTVERSION=	3.0
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTNAME=	nspostgres3_0

MAINTAINER=	jkoshy@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/aolserver/bin/nsd:${PORTSDIR}/www/aolserver \
		${LOCALBASE}/bin/postmaster:${PORTSDIR}/databases/postgresql7
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/nspostgres

USE_GMAKE=	yes
MAKE_ENV+=	POSTGRES=${PREFIX} BUILDPREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspostgres.so ${PREFIX}/aolserver/bin

.include <bsd.port.mk>
