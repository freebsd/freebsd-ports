# New ports collection makefile for:	py-sphinx
# Date created:		2008-09-08
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sphinx
PORTVERSION=	0.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Sphinx-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python documentation generator

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pygments>=0.8:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Jinja>=1.1:${PORTSDIR}/devel/py-Jinja \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Sphinx

.include <bsd.port.mk>
