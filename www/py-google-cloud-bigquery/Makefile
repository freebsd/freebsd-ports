PORTNAME=	google-cloud-bigquery
PORTVERSION=	3.14.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google BigQuery API client library
WWW=		https://github.com/googleapis/python-bigquery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.31.5:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=1.6.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-resumable-media>=0.6.0:www/py-google-resumable-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.47.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.49.1:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.15.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.19.5:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest # tests are broken because they use an outdated Python package 'autotest' that breaks on configure

NO_ARCH=	yes

.include <bsd.port.mk>
