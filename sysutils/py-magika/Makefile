PORTNAME=	magika
DISTVERSIONPREFIX=	python-v
DISTVERSION=	1.0.3
CATEGORIES=	sysutils python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to determine the content type of a file with deep learning
WWW=		https://github.com/google/magika

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnxruntime>=1.17.0:misc/py-onnxruntime@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dacite>=1.9.2:devel/py-dacite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=2.0.1:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=1.0.0:textproc/py-tomli-w@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest

SHEBANG_FILES=	${WRKSRC}/src/magika/cli/magika_client.py \
		${WRKSRC}/src/magika/cli/magika_rust_client_not_found_warning.py

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	magika

WRKSRC_SUBDIR=	python

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 1.0.3: 32 passed, 1 skipped, 1 warning in 12.27s

.include <bsd.port.mk>
