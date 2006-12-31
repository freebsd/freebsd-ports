# New ports collection makefile for: trac-tags
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	tags
PORTVERSION=	0.4
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/downloads/trac-hacks/
PKGNAMEPREFIX=	trac-

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A generic tags frontend for trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
