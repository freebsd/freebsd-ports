# New ports collection makefile for: phppdflib
# Date created:         30 Aug 2001
# Whom:                 HSIN-HSIUNG CHANG <sexbear@tmu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	phppdflib
PORTVERSION=	2.7
CATEGORIES=	print
MASTER_SITES=	http://www.potentialtech.com/
EXTRACT_SUFX=	.tbz

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	An easy to use API for creating PDF files dynamically

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

WRKSRC=		${WRKDIR}/phppdflib
USE_BZIP2=	yes
NO_BUILD=	yes

MYADMDIR?=	www/data/phppdflib

PLIST_SUB+=	MYADMDIR=${MYADMDIR}

do-install:
	${MKDIR} ${PREFIX}/${MYADMDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${MYADMDIR}

.include <bsd.port.mk>
