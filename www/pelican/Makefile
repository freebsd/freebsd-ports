# New ports collection makefile for:	pelican
# Date created:		2011-06-19
# Whom:			Julien Laffaye <jlaffaye@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pelican
PORTVERSION=	2.7.2
CATEGORIES=	www textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Static blog generator

RUN_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils \
		markdown_py:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.5:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_SITELIBDIR}/feedgenerator.py:${PORTSDIR}/www/py-feedgenerator
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYTHON=	2.7+
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
