# New ports collection makefile for:	yui
# Date created:		2008-12-09
# Whom:			BluePex Security Solutions <freebsd-ports@bluepex.com>
#
# $FreeBSD$
#

PORTNAME=	yui
PORTVERSION=	2.6.0
CATEGORIES=	www
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	freebsd-ports@bluepex.com
COMMENT=	The Yahoo! User Interface Library

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
YUIDIR=		${PREFIX}/www/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${MKDIR} ${YUIDIR}
	@${CP} -Rv ${WRKSRC}/build/* ${YUIDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${YUIDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} -Rv ${WRKSRC}/docs/* ${DOCSDIR}
	${CHOWN} -R root:wheel ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rv ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${CHOWN} -R root:wheel ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
