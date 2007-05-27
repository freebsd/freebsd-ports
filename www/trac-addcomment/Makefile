# New ports collection makefile for: trac-addcomment
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	addcomment
PORTVERSION=	0.2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}macro-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Add formatted comments to wiki pages

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracMacroPost-0.1-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-macropost

WRKSRC=		${WRKDIR}/${PORTNAME}macro
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}

.include <bsd.port.mk>
