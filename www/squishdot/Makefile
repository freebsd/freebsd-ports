# New ports collection makefile for: Squishdot-0.7.1
# Date created:		06 Sep 2000
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	squishdot
PORTVERSION=	0.7.1
CATEGORIES=	www
MASTER_SITES=	http://squishdot.org/Download/ \
		http://www.zope.org/Members/chrisw/Squishdot/
DISTNAME=	Squishdot-${PORTVERSION:S/./-/g}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${ZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

NO_BUILD=	YES

ZOPEBASEDIR?=		www/Zope
ZOPEPRODUCTNAME=	Squishdot
ZOPEPRODUCTDIR=		lib/python/Products

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

PLIST_SUB=	ZOPEBASEDIR=${ZOPEBASEDIR}

do-install:
	@${MKDIR} ${PREFIX}/${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} -Rf ${WRKSRC}/* \
		${PREFIX}/${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/

.include <bsd.port.mk>
