# New ports collection makefile for:	pilot_makedoc
# Version required:			0.7
# Date created:				May 10th 1997
# Whom:					jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.4 1998/01/01 17:29:11 asami Exp $
#

PKGNAME=	pilot_makedoc-0.7
CATEGORIES=	palm textproc
MASTER_SITES=	http://www.concentric.net/~rbram/
DISTFILES=	makedoc7.cpp

MAINTAINER=	jfitz@FreeBSD.ORG

NO_WRKSUBDIR=	YES
ALL_TARGET=	pilot_makedoc

do-extract:
		@${MKDIR} ${WRKDIR}
		@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
		@${CP} ${FILESDIR}/Makefile ${WRKDIR}

do-install:
		@${INSTALL_PROGRAM} ${WRKDIR}/pilot_makedoc ${PREFIX}/bin

.include <bsd.port.mk>
