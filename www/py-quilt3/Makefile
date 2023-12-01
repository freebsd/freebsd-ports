PORTNAME=	quilt3
PORTVERSION=	5.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python client for Quilt data hub
WWW=		https://github.com/quiltdata/quilt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aws-requests-auth>=0.4.2:devel/py-aws-requests-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>=1.10.0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonlines>=1.2.0:devel/py-jsonlines@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.12.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>=1.0.0:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5.1.1:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.32:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ANNDATA
ANNDATA_DESC=	Annotated data support

ANNDATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anndata>=0.8.0:devel/py-anndata@${PY_FLAVOR}

.include <bsd.port.mk>
