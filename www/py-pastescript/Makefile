# New ports collection makefile for:	py-pastescript
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	PasteScript
PORTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A pluggable command-line frontend

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3.2:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_SITELIBDIR}/${PYWSGIUTILS_EGG}:${PORTSDIR}/devel/py-wsgiutils
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's

.include <bsd.port.mk>
