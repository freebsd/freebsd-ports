# New ports collection makefile for: Formulator
# Date created:		13 Mar 2005
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	kupu
DISTVERSION=	1.2r2
CATEGORIES=	www zope
MASTER_SITES=	http://kupu.oscom.org/midcom-serveattachmentguid-ed5785a2c523bd36767c80bb2020cd7c/
PKGNAMEPREFIX=	zope-
DISTNAME=	kupu-1.2rc2

MAINTAINER=	x@Vex.Net
COMMENT=	A 'document-centric' client-side editor for Mozilla/IE

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/FileSystemSite/__init__.py:${PORTSDIR}/www/zope-FileSystemSite

USE_ZOPE=	yes
USE_PYTHON=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	kupu

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
