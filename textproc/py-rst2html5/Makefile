# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	rst2html5
PORTVERSION=	1.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Produces HTML5 documents from reStructuredText sources

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.7:${PORTSDIR}/textproc/py-genshi \
	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments \
	${PYTHON_PKGNAMEPREFIX}docutils>=0.11:${PORTSDIR}/textproc/py-docutils

USES=	python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
