# New ports collection makefile for: Squishdot
# Date created:		06 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	squishdot
PORTVERSION=	0.7.3
CATEGORIES=	www
MASTER_SITES=	http://squishdot.org/Download/ \
		http://www.zope.org/Members/chrisw/Squishdot/
DISTNAME=	Squishdot-${PORTVERSION:S/./-/g}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

NO_BUILD=	YES

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	Squishdot
ZOPEPRODUCTDIR=		lib/python/Products

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} -Rf ${WRKSRC}/* \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/

.include <bsd.port.mk>
