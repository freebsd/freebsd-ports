PORTNAME=	mslk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Meta Superintelligence Labs Kernels for PyTorch
WWW=		https://github.com/meta-pytorch/MSLK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	meta-pytorch
GH_PROJECT=	MSLK

# only the pure Python part is built, because the native kernels need CUDA or ROCm
MAKE_ENV=	MSLK_PYTHON_ONLY=1 MSLK_VERSION_OVERRIDE=${PORTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
