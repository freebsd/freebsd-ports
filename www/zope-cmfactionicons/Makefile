# New ports collection makefile for:	zope-cmfactionicons
# Date created:			21 January 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfactionicons
PORTVERSION=	0.9
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/tseaver/CMFActionIcons/CMFActionIcons-0.9/
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFActionIcons-${PORTVERSION}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFActionIcons product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	CMFActionIcons

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}-${PORTVERSION}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

pre-install:
	@${CP} ${WRKDIR}/CMFActionIcons-${PORTVERSION}/README.txt ${WRKDIR}/${ZOPEPRODUCTNAME}-${PORTVERSION}/${ZOPEPRODUCTNAME}/README.txt
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR}/${ZOPEPRODUCTNAME}-${PORTVERSION} ;\
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
