# New ports collection makefile for: zope-zwiki
# Date created:		11 May 2001
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	zwiki
PORTVERSION=	0.9.8
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/simon/ZWiki/ \
		http://zwiki.org/zwikidir/releases/
PKGNAMEPREFIX=	zope-
DISTNAME=	ZWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

USE_PYTHON=	yes
DIST_SUBDIR=	zope

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	ZWiki
ZOPEPRODUCTDIR=		lib/python/Products

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO=		cpio --quiet -pdum -R

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && find * \! -name \*.zexp \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
