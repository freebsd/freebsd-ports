# New ports collection makefile for: ProxyIndex
# Date created:		30 Dec 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	proxyindex
PORTVERSION=	1.1.2
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/infrae/ProxyIndex/ProxyIndex-${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	ProxyIndex-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@Vex.Net
COMMENT=	Plugin catalog index using TALES instead attribute lookup/call

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=ProxyIndex

# yes, some of us are running zope on python 2.3
#PYTHON_VERSION=	python2.3

# You can change this in the environment if you like.
#SZOPEBASEDIR?=		www/Zope

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
