# New ports collection makefile for: KnowledgeKit
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	knowledgekit
PORTVERSION=	1.6.7
CATEGORIES=	www zope
MASTER_SITES=	http://old.zope.org/Members/Bill/Products/KnowledgeKit/${PORTVERSION}/
DISTNAME=	KnowledgeKit-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mechanism for the automatic creation/maintenance of Knowledge Bases

DEPRECATED=	Development seems stalled. Last release is from 1999. \
		Doesn't works with Zope 2.13
EXPIRATION_DATE=	2012-01-06

RUN_DEPENDS=	${ZOPEBASEDIR}/skel/bin/zopectl.in:${PORTSDIR}/www/zope

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
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#; s#%%VER%%#${PORTVERSION}#' \
		${FILESDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
