# New ports collection makefile for:	zope-ttwtype
# Date created:			27 February 2004
# Whom: 					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	ttwtype
PORTVERSION=	1.0.r2
CATEGORIES=	www zope
MASTER_SITES=	SF/collective/TTWType/TTWType-1.0rc2
PKGNAMEPREFIX=	zope-
DISTNAME=	TTWType-1.0rc2

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	TTWType product for CMF/Plone

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/Formulator/__init__.py:${PORTSDIR}/www/zope-formulator \
		${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFFormController/__init__.py:${PORTSDIR}/www/zope-cmfformcontroller

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	TTWType

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

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
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
