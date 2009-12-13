# New ports collection makefile for: trac-pagetopdf
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pagetopdf
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	pagetopdfplugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Export trac wiki pages as PDFs

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		htmldoc:${PORTSDIR}/textproc/htmldoc
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.5+
NO_BUILD=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${PORTNAME}plugin
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
