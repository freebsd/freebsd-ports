# New ports collection makefile for: phppdflib
# Date created:         30 Aug 2001
# Whom:                 HSIN-HSIUNG CHANG <sexbear@tmu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	phppdflib
PORTVERSION=	2.5
CATEGORIES=	print php
MASTER_SITES=	http://www.potentialtech.com/
EXTRACT_SUFX=	.tbz

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	An easy to use API for creating PDF files dynamically

WRKSRC=		${WRKDIR}/phppdflib
USE_BZIP2=	yes
NO_BUILD=	yes

MYADMDIR?=	www/data/phppdflib

PLIST_SUB+=	MYADMDIR=${MYADMDIR}

do-install:
	${MKDIR} ${PREFIX}/${MYADMDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${MYADMDIR}

.include <bsd.port.mk>
