# New ports collection makefile for:	zdaemon
# Date created:		22 Nov, 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zdaemon
PORTVERSION=	2.0.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Daemon Process Control Library and Tools for Unix-bases Systems

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig
RUN_DEPENDS=	${BUILDS_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
