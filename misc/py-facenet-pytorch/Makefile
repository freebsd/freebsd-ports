PORTNAME=	facenet-pytorch
DISTVERSION=	2.6.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	${MASTER_SITE_PYPI}
#MASTER_SITE_SUBDIR=	ed/2e/2d56386bc2f834cdc683743903852cf1428b4e5ee119f16cf808b589d3cd
MASTER_SITE_SUBDIR=	py3/f/facenet-pytorch
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	facenet_pytorch-${DISTVERSION}-py3-none-any
EXTRACT_SUFX=	.whl # this package doesn't distribute source tarballs for this version, only a wheel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pretrained PyTorch face detection and recognition models
WWW=		https://github.com/timesler/facenet-pytorch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/facenet_pytorch-${DISTVERSION}.dist-info/LICENSE.md

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.24.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.2.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>=0.17.0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.0.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_BUILD=	yes
NO_ARCH=	yes

EXTRACT_CMD=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}
WRKSRC=			${WRKDIR}

PEP517_BUILD_DEPEND=	# wheel-only, no build from source
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
