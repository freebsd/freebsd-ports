# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	rst2html5
PORTVERSION=	1.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Produces HTML5 documents from reStructuredText sources

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.7:${PORTSDIR}/textproc/py-genshi \
	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments \
	${PYTHON_PKGNAMEPREFIX}docutils>=0.10:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
