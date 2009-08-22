# New ports collection makefile for:	zope-cmfphoto
# Date created:				29 Dec 2003
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfphoto
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	SF/collective/CMFPhoto/CMFPhoto-${PORTVERSION}
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFPhoto-${PORTVERSION}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFPhoto product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

NO_PACKAGE=	Double python dependency

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	CMFPhoto

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}/Extensions
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

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
