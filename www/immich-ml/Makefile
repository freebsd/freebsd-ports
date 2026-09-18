PORTNAME=	immich-ml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
PORTREVISION=	1
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
		${PYTHON_PKGNAMEPREFIX}rapidocr>0:graphics/py-rapidocr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>0:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/cv2/__init__.py:graphics/opencv

USES=		cpe python
CPE_VENDOR=	futo
CPE_PRODUCT=	immich

USE_GITHUB=	yes
GH_ACCOUNT=	immich-app
GH_PROJECT=	immich

USE_PYTHON=	autoplist pep517
USE_RC_SUBR=	immich_ml

PLIST_FILES=	"@dir(immich,immich,750) /var/db/immich-ml" \
		"@sample(root,wheel,0600) etc/immich-ml.env.sample" \
		etc/newsyslog.conf.d/immich-ml.conf

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		CACHEDIR=/var/db/immich-ml

WRKSRC_SUBDIR=	machine-learning

USERS=		immich
GROUPS=		immich

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/immich-ml
	${INSTALL_DATA} ${FILESDIR}/immich-ml.env.sample ${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich-ml.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich-ml.conf

post-patch:
	@${REINPLACE_CMD} -e 's|"python",|"${PYTHON_CMD}",|' \
		${WRKSRC}/immich_ml/__main__.py

.include <bsd.port.mk>
