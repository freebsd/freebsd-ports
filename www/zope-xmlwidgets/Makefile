# New ports collection makefile for: XMLWidgets
# Date created:		3 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	xmlwidgets
PORTVERSION=	0.10.2
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/infrae/XMLWidgets/XMLWidgets-${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	XMLWidgets-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	XMLWidgets - dynamic translations of ParsedXML to HTML pages

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/ParsedXML/__init__.py:${PORTSDIR}/www/zope-parsedxml

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=XMLWidgets

# yes, some of us are running zope on python 2.3
#PYTHON_VERSION=	python2.3

# You can change this in the environment if you like.
#SZOPEBASEDIR?=		www/Zope

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
