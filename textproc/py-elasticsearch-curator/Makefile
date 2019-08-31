# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-curator
PORTVERSION=	5.6.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Python index manager for Elasticsearch

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.7.24:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2018.10.15:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click6>=6.7:devel/py-click6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>=6.1.0:textproc/py-elasticsearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-aws4auth>=0.9:www/py-requests-aws4auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}voluptuous>=0.9.3:devel/py-voluptuous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
