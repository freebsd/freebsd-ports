# ports collection makefile for:	jfconv
# Date created:			14 May 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jfconv
PORTVERSION=	2000.05.17
CATEGORIES=	palm databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	jconv
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts JFile database to CSV, and vice versa

ALL_TARGET=	# none

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jconv ${PREFIX}/bin/jfconv
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
