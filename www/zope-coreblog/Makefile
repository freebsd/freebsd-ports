# New ports collection makefile for:	zope-coreblog
# Date created:				20 March 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	coreblog
PORTVERSION=	1.2.5
PORTEPOCH=	2
CATEGORIES=	www zope
MASTER_SITES=	http://coreblog.org/junk/
PKGNAMEPREFIX=	zope-
DISTNAME=	COREBlog125
EXTRACT_SUFX=	.tgz

MAINTAINER=	yasi@yasi.to
COMMENT=	A Zope Blog/Weblog/Web-nikki Product

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=COREBlog

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
