# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-py
PORTVERSION=	2.3.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Official Python low-level client for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.8.2:net/py-urllib3

USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
