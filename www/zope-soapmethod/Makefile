# New ports collection makefile for: SOAPMethod
# Date created:		02 Aug 2004
# Whom:			Alexander Leidinger
#
# $FreeBSD$
#

PORTNAME=	soapmethod
PORTVERSION=	2.0
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/EIONET/${ZOPEPRODUCTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION:C/\./-/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The SOAP Method product provides support for remote SOAP methods

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/SOAPpy/__init__.py:${PORTSDIR}/net/py-soappy

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=SOAPMethod

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO_FLAGS=		--quiet -pdum -R

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} ${CPIO_FLAGS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
