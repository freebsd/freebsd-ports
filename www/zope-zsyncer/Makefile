# New ports collection makefile for:	zope-zsyncer
# Date created:			31 January 2005
# Whom:					Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	zsyncer
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	SF/${PORTNAME}/ZSyncer/ZSyncer-${PORTVERSION}
PKGNAMEPREFIX=	zope-
DISTNAME=	ZSyncer-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@vex.net
COMMENT=	Allows multiple Zopes to be synchronized via xmlrpc

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	ZSyncer

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
