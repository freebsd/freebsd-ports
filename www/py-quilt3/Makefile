PORTNAME=	quilt3
PORTVERSION=	7.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python client for Quilt data hub
WWW=		https://github.com/quiltdata/quilt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build08>=0.8.15<0.9.0:devel/py-uv-build08@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.21.7:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonlines>=1.2.0:devel/py-jsonlines@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0<3.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.12.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>=1.0.0:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5.1.1:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.32:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ANNDATA PYARROW
ANNDATA_DESC=	Annotated data support
PYARROW_DESC=	Apache Arrow support

ANNDATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anndata>=0.8.0:devel/py-anndata@${PY_FLAVOR}
PYARROW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.14.0,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>=0.19.2,1:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyarrow>=0.14.1:databases/py-pyarrow@${PY_FLAVOR}

.include <bsd.port.mk>
