# New ports collection makefile for: nspostgres
# Date created: 	30 January 2001
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	nspostgres
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTNAME=	nspostgres3_0

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A driver to access PostgreSQL databases from Aolserver

BUILD_DEPENDS=	${LOCALBASE}/aolserver/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	Use www/aolserver with WITH_NSPOSTGRES=1 instead.
IGNORE=		${DEPRECATED}

USE_PGSQL=	yes

WRKSRC=		${WRKDIR}/nspostgres

USE_GMAKE=	yes
MAKE_ENV+=	POSTGRES=${PREFIX} BUILDPREFIX=${PREFIX}
PLIST_FILES=	aolserver/bin/nspostgres.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspostgres.so ${PREFIX}/aolserver/bin

.include <bsd.port.mk>
