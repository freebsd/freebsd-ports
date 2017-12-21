# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	5.4.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official Python low-level client for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.8.2:net/py-urllib3@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
