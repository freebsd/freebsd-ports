# New ports collection makefile for: Formulator
# Date created:		3 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	formulator
PORTVERSION=	1.6.0
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/infrae/Formulator/Formulator-${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	Formulator-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	Formulator - HTML form generatation and validation system

USE_PYTHON=		yes
USE_ZOPE=		yes
DIST_SUBDIR=	zope

CONFLICTS=	plone-*

ZOPEPRODUCTNAME=	Formulator

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO=		cpio --quiet -pdum -R

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
