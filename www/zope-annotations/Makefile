# New ports collection makefile for: Annotations
# Date created:		30 Dec 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	annotations
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/infrae/Annotations/Annotations-${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	Annotations-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	A generic way to add information to arbitrary Zope objects

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=Annotations

# yes, some of us are running zope on python 2.3
#PYTHON_VERSION=	python2.3

# You can change this in the environment if you like.
#SZOPEBASEDIR?=		www/Zope

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} --quiet -pdum -R ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
