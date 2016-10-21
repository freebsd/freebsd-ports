# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-py
PORTVERSION=	5.0.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Official Python low-level client for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.8.2:net/py-urllib3

NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
