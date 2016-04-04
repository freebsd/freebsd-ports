# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	rst2html5
PORTVERSION=	1.7.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Produces HTML5 documents from reStructuredText sources

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.7:textproc/py-genshi \
	${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments \
	${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils

USES=	python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
