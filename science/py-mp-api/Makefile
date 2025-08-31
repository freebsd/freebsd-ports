PORTNAME=	mp-api
DISTVERSION=	0.34.0
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for server for the Materials Project
WWW=		https://materialsproject.github.io/api/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}custodian>0:devel/py-custodian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emmet-core>=0.39.8:science/py-emmet-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2022.3.12:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpcontribs-client>=5.0.10:science/py-mpcontribs-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.8.2:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen-analysis-alloys>=0.0.3:science/py-pymatgen-analysis-alloys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>=2022.3.7:science/py-pymatgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.1:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
