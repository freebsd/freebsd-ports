# New ports collection makefile for: Formulator
# Date created:		13 Mar 2005
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	kupu
PORTVERSION=	1.3.5
CATEGORIES=	www zope
MASTER_SITES=	http://kupu.oscom.org/midcom-serveattachmentguid-e73585dd09549cfe130f91177d889819/
PKGNAMEPREFIX=	zope-

MAINTAINER=	x@vex.net
COMMENT=	A 'document-centric' client-side editor for Mozilla/IE

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/FileSystemSite/__init__.py:${PORTSDIR}/www/zope-FileSystemSite

USE_ZOPE=	yes
USE_PYTHON=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	kupu

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

CONFLICTS=	plone-[0-9]*

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
