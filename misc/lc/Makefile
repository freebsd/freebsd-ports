# New ports collection makefile for:   lc
# Date created:        13 November 1999
# Whom:                jsellens
#
# $FreeBSD$
#

PORTNAME=	lc
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.generalconcepts.com/resources/software/

MAINTAINER=	jsellens@generalconcepts.com
COMMENT=	An alternative to ls(1)

MAN1=		lc.1
PLIST_FILES=	bin/lc

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/lc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/lc.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
