# New ports collection makefile for:	gregarius
# Date created:		2006-12-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gregarius
PORTVERSION=	0.5.4
CATEGORIES=	www
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	Web-based RSS/RDF/ATOM news aggregator

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}

.include <bsd.port.mk>
