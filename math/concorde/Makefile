# New ports collection makefile for:	concorde
# Date created:				3 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	concorde
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.caam.rice.edu/pub/software/keck/
DISTNAME=	co991215
EXTRACT_SUFX=	.tgz

MAINTAINER=	dbader@eece.unm.edu

WRKSRC=		${WRKDIR}/concorde

GNU_CONFIGURE=  yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/concorde.a ${PREFIX}/lib/libconcorde.a
	${INSTALL_DATA} ${WRKSRC}/concorde.h ${PREFIX}/include

.include <bsd.port.mk>
