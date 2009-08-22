# New ports collection makefile for:	zope-cmfformcontroller
# Date created:			20 January 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfformcontroller
PORTVERSION=	1.0.2
CATEGORIES=	www zope
MASTER_SITES=	SF/collective/CMFFormController/${PORTVERSION}
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFFormController-${PORTVERSION}
EXTRACT_SUFX=.tgz

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFFormController product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	CMFFormController

PLIST=	${WRKDIR}/pkg-plist
WRKSRC=	${WRKDIR}/${ZOPEPRODUCTNAME}

CONFLICTS=	plone[0-9]*-[0-9]*

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

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
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
