# New ports collection makefile for: Zope-PTK
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	zope-cmf
PORTVERSION=	1.4.6
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Products/CMF/CMF-${PORTVERSION}/
DISTNAME=	CMF-${PORTVERSION}

MAINTAINER=	filippo@widestore.net
COMMENT=	The Zope Content Management Framework (CMF)

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/CMF*

do-install:
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
.for cmfdir in CMFCalendar CMFCore CMFDefault CMFTopic DCWorkflow
	@${CP} -R ${WRKSRC}/${cmfdir} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
.endfor

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
