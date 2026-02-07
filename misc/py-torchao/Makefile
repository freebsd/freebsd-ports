PORTNAME=	torchao
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Package for applying ao techniques to GPU models
WWW=		https://docs.pytorch.org/ao/stable/index.html \
		https://github.com/pytorch/ao

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	ao
GH_TUPLE=	NVIDIA:cutlass:e51efbf:cutlass/third_party/cutlass

NO_ARCH=	yes

# tests fail with: caught unexpected SystemExit!

.include <bsd.port.mk>
