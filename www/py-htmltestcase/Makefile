# Ports collection makefile for:	py-htmltestcase
# Date created:			24 June 2004
# Whom:				"Choe, Cheng-Dae" <whitekid@netian.com>
#
# $FreeBSD$
#

PORTNAME=	htmltestcase
PORTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	http://chriscurvey.com:8080/curveyConsulting/HtmlUnit/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HtmlTestCase-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python html unit testing

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ClientCookie/__init__.py:${PORTSDIR}/devel/py-clientcookie\
		${PYTHON_SITELIBDIR}/ClientForm.py:${PORTSDIR}/www/py-clientform

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
