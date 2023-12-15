PORTNAME=	torchvision
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.2
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Datasets, transforms and models specific to computer vision
WWW=		https://pytorch.org/vision/stable/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png
PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests run in a very high memory

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	vision

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/_C.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/image.so

.include <bsd.port.mk>
