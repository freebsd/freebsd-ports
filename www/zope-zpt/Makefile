# New ports collection makefile for: zope-zpt
# Date created:		15 August 2001
# Whom:			Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zpt
PORTVERSION=	1.4.1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/4am/ZPT/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTFILES=	PageTemplates-${PORTVERSION}.tar.gz \
		TAL-${PORTVERSION}.tar.gz \
		ZTUtils-${ZTUVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zope Page Templates separate design and logic in Zope applications

RUN_DEPENDS=	${ZOPEBASEDIR}/skel/bin/zopectl.in:${PORTSDIR}/www/zope

DEPRECATED=	"already included in Zope versions 2.5 and above"
USE_PYTHON=	yes
DIST_SUBDIR=	zope

BROKEN=		Does not build after python 2.4 update
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

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
CPIO_OPTIONS=	--quiet -pdum -R

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
	@ cd ${WRKDIR}/${product} && ${FIND} * \
	  | ${CPIO} ${CPIO_OPTIONS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPYTHONDIR}/${product}/
.endfor
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} * \( -name examples -a -prune \) -o -print \
	  | ${CPIO} ${CPIO_OPTIONS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ ${MKDIR} ${ZOPEBASEDIR}/import
	@ ${INSTALL_DATA} ${WRKSRC}/examples/zpt_examples.zexp \
	  ${ZOPEBASEDIR}/import

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
