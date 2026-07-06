PORTNAME=	comfy-kitchen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.16
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ComfyUI: Fast kernel library for Diffusion inference
WWW=		https://github.com/Comfy-Org/comfy-kitchen

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>=2.0.0:devel/py-nanobind@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>=2.5.0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Comfy-Org

NO_ARCH=	yes # it would have binaries when CUDA would be enabled

# CUDA is not available on FreeBSD
MAKE_ENV+=	COMFY_KITCHEN_NO_CUDA=1

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

tests as of 0.2.16:
# Results (37.06s):
#        178 passed
#        377 skipped
#          9 warnings

.include <bsd.port.mk>
