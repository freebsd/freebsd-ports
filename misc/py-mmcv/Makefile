PORTNAME=	mmcv
#DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenMMLab: Foundational library for computer vision research
WWW=		https://mmcv.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ninja:devel/ninja \
		${PREFIX}/include/pybind11/pybind11.h:devel/pybind11 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}addict>0:devel/py-addict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mmengine>=0.3.0:misc/py-mmengine@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}yapf>0:textproc/py-yapf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		compiler:c++17-lang localbase python
USE_PYTHON=	distutils cython autoplist # pytest: many test dependencies are missing

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/mmcv/_ext${PYTHON_TAG}.so

.include <bsd.port.mk>
