# New ports collection makefile for: trac-nav
# Date created:                      January 03 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	nav
PORTVERSION=	3.92p6
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/downloads/trac-hacks/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracNav-${PORTVERSION:S/p/pre/}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A fully customizable navigation bar for Trac

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools \
		tracd:${PORTSDIR}/www/trac
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/p/pre/} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
