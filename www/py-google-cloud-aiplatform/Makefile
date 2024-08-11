PORTNAME=	google-cloud-aiplatform
DISTVERSION=	1.61.0
CATEGORIES=	www # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vertex AI API client library
WWW=		https://github.com/googleapis/python-aiplatform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.34.1:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=1.32.0:www/py-google-cloud-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-bigquery>=1.15.0:www/py-google-cloud-bigquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-resource-manager>=1.3.3:www/py-google-cloud-resource-manager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=14.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.22.0<2.0.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.19.5:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>0:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_LDCONFIG=	yes
USE_PYTHON=	distutils autoplist # TODO pytest - it has a large and complex set of dependencies

NO_ARCH=	yes

.include <bsd.port.mk>
