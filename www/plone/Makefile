# New ports collection makefile for: plone
# Date created:		09 Jan 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	plone
PORTVERSION=	1.0.r1
CATEGORIES=	www
MASTER_SITES= 	http://unc.dl.sourceforge.net/sourceforge/plone/
DISTNAME=	CMFPlone1.0RC1
DIST_SUBDIR=	zope

MAINTAINER=	ports@freebsd.org

RUN_DEPENDS=    ${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope \
		${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

WRKSRC=		${WRKDIR}/CMFPlone-1.0RC1
NO_BUILD=	yes
MODULES=	CMFPlone DCWorkflow Formulator i18n

# You can change this in the environment if you like.
SZOPEBASEDIR?=          www/Zope

# Don't change these
ZOPEBASEDIR=            ${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=
ZOPEPRODUCTDIR=         lib/python/Products

PLIST_SUB=		ZOPEBASEDIR=${SZOPEBASEDIR}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@(cd ${WRKSRC} && ${CP} -R ${MODULES} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR})

.include <bsd.port.mk>
