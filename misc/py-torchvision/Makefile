PORTNAME=	torchvision
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Datasets, transforms and models specific to computer vision
WWW=		https://pytorch.org/vision/stable/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png
PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
PY_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>=5.3.0:graphics/py-pillow@${PY_FLAVOR} # image backend
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		jpeg python
USE_PYTHON=	distutils autoplist pytest # tests run in a very high memory ; in 0.17.1 tests fail to run, see https://github.com/pytorch/vision/issues/8278

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	vision

MAKE_ENV=	TORCHVISION_INCLUDE=${LOCALBASE}/include # workaround for build failure suggested here: https://github.com/pytorch/vision/issues/8397#issuecomment-2168351425

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/_C.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/image.so

.include <bsd.port.mk>
