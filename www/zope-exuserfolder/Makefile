# New ports collection makefile for: Zope-XUF
# Date created:		1 Jul 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	exuserfolder
PORTVERSION=	0.20.0
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	exuserfolder
PKGNAMEPREFIX=	zope-
DISTNAME=	exUserFolder-0_20_0
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	Extensible User Folder - Custom & database authenticatoin for Zope

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

USE_PYTHON=	yes
DIST_SUBDIR=	zope

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	exUserFolder
ZOPEPRODUCTDIR=		lib/python/Products

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO=		cpio --quiet -pdum -R

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
