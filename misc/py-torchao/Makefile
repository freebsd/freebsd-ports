PORTNAME=	torchao
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pytorch/ao/commit/
PATCHFILES=	cf7d0b178f989bf43fff27a4246cf2cab9175ac9.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Package for applying ao techniques to GPU models
WWW=		https://docs.pytorch.org/ao/stable/index.html \
		https://github.com/pytorch/ao

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
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
