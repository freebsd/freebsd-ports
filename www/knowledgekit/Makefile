# New ports collection makefile for: KnowledgeKit
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	knowledgekit
PORTVERSION=	1.6.7
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
DISTNAME=	KnowledgeKit-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

NO_BUILD=	YES
PKGMESSAGE=	${WRKDIR}/.MESSAGE

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	KnowledgeKit
ZOPEPRODUCTDIR=		lib/python/Products

WRKSRC=		${WRKDIR}/import

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

do-install:
	@${CP} ${WRKSRC}/* \
		${ZOPEBASEDIR}/import
	@perl -pe 's#%%PREFIX%%#${PREFIX}#; s#%%VER%%#${PORTVERSION}#' ${FILESDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
