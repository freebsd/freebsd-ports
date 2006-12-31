# New ports collection makefile for: trac-wikinotification
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	wikinotification
PORTVERSION=	0.1.0p4
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/downloads/trac-hacks/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/rc/}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Allow email notifications on wiki page changes

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-1.1_r1-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-ctxtnavadd
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/p/rc/} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
