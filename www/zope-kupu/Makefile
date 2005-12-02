# New ports collection makefile for: Formulator
# Date created:		13 Mar 2005
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	kupu
PORTVERSION=	1.2.2
CATEGORIES=	www zope
MASTER_SITES=	http://kupu.oscom.org/midcom-serveattachmentguid-19cdb52c4a9a4be7720d0d694fcfe32d/
PKGNAMEPREFIX=	zope-

MAINTAINER=	x@vex.net
COMMENT=	A 'document-centric' client-side editor for Mozilla/IE

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
