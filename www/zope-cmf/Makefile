# New ports collection makefile for: Zope-PTK
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	zope-cmf
PORTVERSION=	1.4.8
CATEGORIES=	www zope
MASTER_SITES=	http://old.zope.org/Products/CMF/CMF-${PORTVERSION}/
DISTNAME=	CMF-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Zope Content Management Framework (CMF)

DEPRECATED=	Doesn't work with modern Zope versions
EXPIRATION_DATE=	2012-02-06

USE_PYTHON=	2.4
USE_ZOPE=	2.7
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
