# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	rst2html5
PORTVERSION=	0.10
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Produces HTML5 documents from reStructuredText sources

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.6:${PORTSDIR}/textproc/py-genshi \
	${PYTHON_PKGNAMEPREFIX}pygments>=1.5:${PORTSDIR}/textproc/py-pygments \
	${PYTHON_PKGNAMEPREFIX}docutils>=0.10:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
