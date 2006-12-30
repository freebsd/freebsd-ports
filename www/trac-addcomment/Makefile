# New ports collection makefile for: trac-addcomment
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	addcomment
PORTVERSION=	0.1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/downloads/trac-hacks/
PKGNAMEPREFIX=	trac-

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Add formatted comments to wiki pages

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
