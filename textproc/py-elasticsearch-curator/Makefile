# Created by: Dan Langille <dvl@FreeBSD.org>

PORTNAME=	elasticsearch-curator
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.4
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Python index manager for Elasticsearch

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.7.24:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2018.10.15:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click7>=7.1.2:devel/py-click7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>=7.15.1:textproc/py-elasticsearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-aws4auth>=0.9:www/py-requests-aws4auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.4:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}voluptuous>=0.9.3:devel/py-voluptuous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	elastic
GH_PROJECT=	curator
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
