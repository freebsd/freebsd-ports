# New ports collection makefile for: ProxyIndex
# Date created:		30 Dec 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	proxyindex
PORTVERSION=	1.2
CATEGORIES=	www zope
MASTER_SITES=	http://www.infrae.com/download/ProxyIndex/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	ProxyIndex-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	Plugin catalog index using TALES instead attribute lookup/call

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=ProxyIndex

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
