# New ports collection makefile for: ParsedXML
# Date created:		3 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	parsedxml
PORTVERSION=	1.4
CATEGORIES=	www zope
MASTER_SITES=	http://www.infrae.com/download/ParsedXML/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	ParsedXML-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	ParsedXML - access and manipulated XML documents within Zope

RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

BROKEN=		Broken dependency
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	ParsedXML

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
