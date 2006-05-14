# New ports collection makefile for:	zope-zwiki
# Date created:		11 May 2001
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	zwiki
PORTVERSION=	0.53.0
CATEGORIES=	www zope
MASTER_SITES=	http://zwiki.org/releases/
PKGNAMEPREFIX=	zope-
DISTNAME=	ZWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	x@vex.net
COMMENT=	A WikiWikiWeb product for Zope (colaborative web site system)

USE_ZOPE=	yes
USE_PYTHON=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	ZWiki

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${CHMOD} -R og+rX ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
