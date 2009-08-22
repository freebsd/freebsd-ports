# New ports collection makefile for: zope-archetypes
# Date created:		11 Nov 2003
# Whom:			filippo@widestore.net
#
# $FreeBSD$
#

PORTNAME=	archetypes
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	www zope
MASTER_SITES=	SF/${PORTNAME}/Archetypes/${PORTVERSION}
PKGNAMEPREFIX=	zope-
DISTNAME=	Archetypes-${PORTVERSION}-final
DIST_SUBDIR=	zope

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for the development of new Content Types in Zope/CMF/Plone

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFPlone/__init__.py:${PORTSDIR}/www/plone \
	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/PortalTransforms/__init__.py:${PORTSDIR}/www/zope-portaltransforms \
	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/validation/__init__.py:${PORTSDIR}/www/zope-validation \
	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/generator/__init__.py:${PORTSDIR}/www/zope-generator \
	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/MimetypesRegistry/__init__.py:${PORTSDIR}/www/zope-mimetypesregistry

ZOPEPRODUCTNAME=	Archetypes
WRKSRC=${WRKDIR}/${ZOPEPRODUCTNAME}
USE_ZOPE=	yes
USE_PYTHON=	yes
PLIST=	${WRKDIR}/pkg-plist

CONFLICTS=	plone[0-9]*-[0-9]*

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} && \
	for f in `${FIND} ${ZOPEPRODUCTNAME} -type f`; do \
			${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${ZOPEPRODUCTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done; \

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

.include <bsd.port.mk>
