# New ports collection makefile for: ParsedXML
# Date created:		3 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	parsedxml
PORTVERSION=	1.3.1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/faassen/ParsedXML/${PORTVERSION}/
MASTER_SITE_SUBDIR=	formulator
PKGNAMEPREFIX=	zope-
DISTNAME=	ParsedXML-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	ParsedXML - access and manipulated XML documents within Zope

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope \
				${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

USE_PYTHON=		yes
USE_ZOPE=		yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	ParsedXML

# yes, some of us are running zope on python 2.2
#PYTHON_VERSION= python2.2

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
