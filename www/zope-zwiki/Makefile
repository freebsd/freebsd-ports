# New ports collection makefile for: zope-zwiki
# Date created:		11 May 2001
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	zwiki
PORTVERSION=	0.27.1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/simon/ZWiki/ \
		http://zwiki.org/zwikidir/releases/
PKGNAMEPREFIX=	zope-
DISTNAME=	ZWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	A WikiWikiWeb product for Zope

USE_ZOPE=	yes
USE_PYTHON=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	ZWiki
ZOPEPRODUCTDIR=		lib/python/Products

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO=		cpio --quiet -pdum -R

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} * \! -name \*.zexp \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
