# New ports collection makefile for: trac-pagetopdf
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pagetopdf
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/downloads/trac-hacks/
PKGNAMEPREFIX=	trac-
DISTNAME=	pagetopdfplugin

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Export trac wiki pages as PDFs

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		htmldoc:${PORTSDIR}/textproc/htmldoc
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${DISTNAME}/0.10
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
