# New ports collection makefile for:	zope-plonelanguagetool
# Date created:			July 4 2004
# Whom:					Khairil Yusof <kaeru@inigo-tech.com>
#
# $FreeBSD$
#

PORTNAME=	plonelanguagetool
PORTVERSION=	0.4
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	collective
PKGNAMEPREFIX=	zope-
DISTNAME=	PloneLanguageTool-${PORTVERSION}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	PloneLanguageTool product for Zope

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFPlone/__init__.py:${PORTSDIR}/www/plone \
				${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/I18NLayer/__init__.py:${PORTSDIR}/www/zope-i18nlayer

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

EXTRACT_CMD=	tar
EXTRACT_BEFORE_ARGS=	-zxvf
EXTRACT_AFTER_ARGS=	--exclude CVS

ZOPEPRODUCTNAME=	PloneLanguageTool

PLIST=	${WRKDIR}/pkg-plist
WRKSRC=	${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -x skins ${WRKSRC}

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
