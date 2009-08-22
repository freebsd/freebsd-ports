# New ports collection makefile for:	zope-mimetypesregistry
# Date created:				06 Oct 2004
# Whom:					Filippo Natali
#
# $FreeBSD$
#

PORTNAME=	mimetypesregistry
PORTVERSION=	1.3.6
CATEGORIES=	www zope
MASTER_SITES=	SF/archetypes/Archetypes/1.3.4
PKGNAMEPREFIX=	zope-
DISTNAME=	MimetypesRegistry-${PORTVERSION}-final01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MimetypesRegistry product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	MimetypesRegistry

WRKSRC=	${WRKDIR}/${ZOPEPRODUCTNAME}
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

post-install:
.if !defined(BATCH)
	@${ECHO} Restart Zope to complete installation of ${PORTNAME}
.endif

.include <bsd.port.mk>
