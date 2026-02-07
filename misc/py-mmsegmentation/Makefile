PORTNAME=	mmsegmentation
#DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenMMLab: Semantic Segmentation Toolbox and Benchmark
WWW=		https://mmsegmentation.readthedocs.io/en/latest/

LICENSE=	APACHE20

#BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist # pytest: many test dependencies are missing

NO_ARCH=	yes

.include <bsd.port.mk>
