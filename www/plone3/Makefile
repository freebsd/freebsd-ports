# New ports collection makefile for: plone
# Date created:		09 Jan 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	plone
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	plone
DISTNAME=	CMFPlone1.0.1
DIST_SUBDIR=	zope

MAINTAINER=	ports@freebsd.org
COMMENT=	A user friendly implementation of the CMF written on top of ZOPE

RUN_DEPENDS=    ${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope \
		${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf
USE_PYTHON=	yes
PYTHON_VERSION=	python2.1

WRKSRC=		${WRKDIR}/CMFPlone-1.0.1
MODULES=	CMFPlone DCWorkflow Formulator i18n

# You can change this in the environment if you like.
SZOPEBASEDIR?=          www/Zope

# Don't change these
ZOPEBASEDIR=            ${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=
ZOPEPRODUCTDIR=         lib/python/Products

PLIST_SUB=		ZOPEBASEDIR=${SZOPEBASEDIR}

do-build:
	@for m in ${MODULES}; do \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/$$m; \
	done

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@(cd ${WRKSRC} && ${CP} -R ${MODULES} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR})

.include <bsd.port.mk>
