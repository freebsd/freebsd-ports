# New ports collection makefile for:	zope-zsyncer
# Date created:			31 January 2005
# Whom:					Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	zsyncer
PORTVERSION=	0.7.0
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	zsyncer
PKGNAMEPREFIX=	zope-
DISTNAME=	ZSyncer-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@vex.net
COMMENT=	Allows multiple Zopes to be synchronized via xmlrpc

BROKEN=		Incomplete pkg-plist

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/ZSyncer

PRODUCTNAME=	ZSyncer

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/
	@${CHMOD} -R og+rX ${WRKSRC}/

do-install:
	${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
