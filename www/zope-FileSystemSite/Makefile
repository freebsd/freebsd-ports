# New ports collection makefile for: FileSystemSite
# Date created:		16 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	FileSystemSite
PORTVERSION=	1.4.2
CATEGORIES=	www zope
MASTER_SITES=	http://www.infrae.com/download/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	zope-
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@vex.net
COMMENT=	Enable file system based sites within Zope

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=${PORTNAME}

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
