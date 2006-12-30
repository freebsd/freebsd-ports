# New ports collection makefile for: trac-ctxtnavadd
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ctxtnavaddplugin
PORTVERSION=	1.1.r1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/downloads/trac-hacks/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Add links to the ctxtnav bar from other plugins

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${PORTNAME}/0.10
PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/.r/_r/} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
