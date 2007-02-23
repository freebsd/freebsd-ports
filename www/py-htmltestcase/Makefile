# Ports collection makefile for:	py-htmltestcase
# Date created:			24 June 2004
# Whom:				"Choe, Cheng-Dae" <whitekid@netian.com>
#
# $FreeBSD$
#

PORTNAME=	htmltestcase
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://chriscurvey.com:8080/curveyConsulting/HtmlUnit/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HtmlTestCase-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python html unit testing

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ClientCookie/__init__.py:${PORTSDIR}/devel/py-clientcookie\
		${PYTHON_SITELIBDIR}/${PYCLIENTFORM_EGG}:${PORTSDIR}/www/py-clientform

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

PYCLIENTFORM_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-clientform/Makefile -V PYCLIENTFORM_EGG

.include <bsd.port.post.mk>
