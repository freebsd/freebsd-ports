# New ports collection makefile for: zope-zpt
# Date created:		15 August 2001
# Whom:			Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zpt
PORTVERSION=	1.4.1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/4am/ZPT/
PKGNAMEPREFIX=	zope-
DISTFILES=	PageTemplates-${PORTVERSION}.tar.gz \
		TAL-${TALVERSION}.tar.gz \
		ZTUtils-${ZTUVERSION}.tar.gz

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

USE_PYTHON=	yes
DIST_SUBDIR=	zope

TALVERSION=	1.4.1
ZTUVERSION=	1.1.3

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	PageTemplates
ZOPEPYTHONDIR=		lib/python
ZOPEPRODUCTDIR=		${ZOPEPYTHONDIR}/Products
ZOPEPRODUCTS=		PageTemplates TAL ZTUtils

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO=		cpio --quiet -pdum -R

do-build:
.for product in ${ZOPEPRODUCTS}
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/${product}
.endfor

do-install:
.for product in ${ZOPEPRODUCTS}
	@ ${CHMOD} -R og+rX ${WRKDIR}/${product}
.endfor
.for product in TAL ZTUtils
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPYTHONDIR}/${product}
	@ cd ${WRKDIR}/${product} && find * \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPYTHONDIR}/${product}/
.endfor
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && find * \( -name examples -a -prune \) -o -print \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ ${MKDIR} ${ZOPEBASEDIR}/import
	@ ${INSTALL_DATA} ${WRKSRC}/examples/zpt_examples.zexp \
	  ${ZOPEBASEDIR}/import

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
