# New ports collection makefile for: zope-archetypes
# Date created:		11 Nov 2003
# Whom:			filippo@widestore.net
#
# $FreeBSD$
#

PORTNAME=	archetypes
PORTVERSION=	1.2.4
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	archetypes
PKGNAMEPREFIX=	zope-
DISTNAME=	archetypes-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	zope

MAINTAINER=	filippo@widestore.net
COMMENT=	Framework for the development of new Content Types in Zope/CMF/Plone

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/CMFPlone/__init__.py:${PORTSDIR}/www/plone \
	${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/PortalTransforms/__init__.py:${PORTSDIR}/www/zope-cmftransforms

WRKSRC=${WRKDIR}/${DISTNAME}
USE_ZOPE=	yes
USE_PYTHON=	yes
MODULES=	ArchExample ArchGenXML Archetypes
PYTHON_MODULES=	validation generator

do-build:
	-@for m in ${MODULES}; do \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/$$m; \
	done

do-install:
	@for pym in ${PYTHON_MODULES}; do \
		cd ${WRKSRC}/$$pym && ${PYTHON_CMD} setup.py install; \
	done
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@(cd ${WRKSRC} && ${CP} -R ${MODULES} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR})

.include <bsd.port.mk>
