# New ports collection makefile for: zope-cmfquickinstaller
# Date created:		5 Jan 2004
# Whom:				Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfquickinstaller
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	collective
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFQuickInstallerTool_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFQuickInstaller is a product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=		${WRKDIR}/CMFQuickInstallerTool

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/interfaces/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	-@${RM} ${WRKSRC}/.cvsignore
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
