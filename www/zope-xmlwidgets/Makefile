# New ports collection makefile for: XMLWidgets
# Date created:		3 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	xmlwidgets
PORTVERSION=	0.13
CATEGORIES=	www zope
MASTER_SITES=	http://www.infrae.com/download/XMLWidgets/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	XMLWidgets-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@vex.net
COMMENT=	XMLWidgets - dynamic translations of ParsedXML to HTML pages

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/ParsedXML/__init__.py:${PORTSDIR}/www/zope-parsedxml

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=XMLWidgets

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
