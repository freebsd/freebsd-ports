# New ports collection makefile for: FileSystemSite
# Date created:		16 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	FileSystemSite
PORTVERSION=	1.4.1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/infrae/FileSystemSite/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
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
