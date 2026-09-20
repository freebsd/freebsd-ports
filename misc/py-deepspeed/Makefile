PORTNAME=	deepspeed
DISTVERSION=	0.19.6
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DeepSpeed library for ChatGPT-like model training
WWW=		http://www.deepspeed.ai/ \
		https://github.com/deepspeedai/DeepSpeed

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}einops>0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hjson>0:textproc/py-hjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ninja>0:devel/py-ninja@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo2>0:sysutils/py-py-cpuinfo2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		bash:shells/bash
		# many extras exist in setup.py

USES=		python shebangfix
USE_PYTHON=	distutils autoplist pytest # some tests fail, tests consume gigabytes of disk space

SHEBANG_FILES=	bin/ds_ssh

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.19.6: 2 failed, 44 passed, 1 warning in 2.87s, see https://github.com/deepspeedai/DeepSpeed/issues/8554

.include <bsd.port.mk>
