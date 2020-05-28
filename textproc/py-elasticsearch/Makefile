# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	7.7.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official Python low-level client for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:textproc/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	REQUESTS
OPTIONS_DEFAULT=REQUESTS
REQUESTS_DESC=	Enable requests support

REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.4.0<3.0.0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
