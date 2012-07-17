# New ports collection makefile for:	py-sphinx
# Date created:		2008-09-08
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sphinx
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Sphinx-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python documentation generator

LICENSE=	BSD

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pygments>=1.2:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.7:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Sphinx

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

post-install:
	@${SETENV} PYTHONPATH=${PYTHONPREFIX_SITELIBDIR} \
	${PYTHON_CMD} -m sphinx.pycode.pgen2.driver -c 'import load_grammar'

.include <bsd.port.mk>
