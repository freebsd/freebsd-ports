# New ports collection makefile for: zope-zpt
# Date created:		15 August 2001
# Whom:			Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guf
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/Zen/GenericUserFolder/1-2-4/
PKGNAMEPREFIX=	zope-
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION:S|.|-|g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	A roll-your-own user folder product for Zope

DEPRECATED=	"no longer being developed: use SimpleUserFolder or exUserFolder instead"

USE_ZOPE=	yes
USE_PYTHON=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	GenericUserFolder

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
CPIO_OPTIONS=	--quiet -pdum -R

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} * | ${CPIO} ${CPIO_OPTIONS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
