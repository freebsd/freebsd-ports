# New ports collection makefile for:	zope-cmfphoto
# Date created:				29 Dec 2003
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfphoto
PORTVERSION=	0.4.r1
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	collective
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFPhoto-0.4rc1

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFPhoto product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=		${WRKDIR}/CMFPhoto

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/Extensions/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/i18n/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
