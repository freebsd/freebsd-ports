PORTNAME=	immich-ml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	www python

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Machine-learning service for Immich
WWW=		https://immich.app/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiocache>0:devel/py-aiocache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ftfy>0:textproc/py-ftfy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}insightface>0:misc/py-insightface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ml-dtypes>0:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnxruntime>0:misc/py-onnxruntime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>0:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>0:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>0:www/py-uvicorn@${PY_FLAVOR} \
		opencv>0:graphics/opencv

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	immich-app
GH_PROJECT=	immich

USE_PYTHON=	autoplist pep517
USE_RC_SUBR=	immich_ml

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

WRKSRC_SUBDIR=	machine-learning

USERS=		immich
GROUPS=		immich

post-patch:
	@${REINPLACE_CMD} -e "s|uvicorn\[standard\]|uvicorn|" \
		-e "/opencv-python-headless/d" \
		-e "/rapidocr/d" \
		${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e 's|"python",|"${PYTHON_CMD}",|' \
		${WRKSRC}/immich_ml/__main__.py

.include <bsd.port.mk>
