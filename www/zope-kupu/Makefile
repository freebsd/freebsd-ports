# New ports collection makefile for: Formulator
# Date created:		13 Mar 2005
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	kupu
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://kupu.oscom.org/midcom-serveattachmentguid-6b4584286e6cd5bbf2f82f0a83ead0e2/
PKGNAMEPREFIX=	zope-

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
