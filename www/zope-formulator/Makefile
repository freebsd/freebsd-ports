# New ports collection makefile for: Formulator
# Date created:		3 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	formulator
PORTVERSION=	1.8.0
CATEGORIES=	www zope
MASTER_SITES=	http://www.infrae.com/download/Formulator/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	Formulator-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@vex.net
COMMENT=	HTML form generatation and validation system for Zope

USE_PYTHON=		yes
USE_ZOPE=		yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	Formulator

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
