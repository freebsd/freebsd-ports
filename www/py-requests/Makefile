# New ports collection makefile for: py-requests
# Date created:		2011-07-30
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	requests
PORTVERSION=	0.7.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Requests is an elegant and simple HTTP library for Python

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gevent/__init__.py:${PORTSDIR}/devel/py-gevent

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
