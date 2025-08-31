PORTNAME=	openpiv
PORTVERSION=	0.23.8
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python module for Particle Image Velocimetry
WWW=		http://www.openpiv.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.12.0:graphics/py-scikit-image@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	OpenPIV
GH_PROJECT=	openpiv-python

NO_ARCH=	yes

OPTIONS_DEFINE=	EXTRA
EXTRA_DESC=	Install additional Python packages (for tutorial/examples)

EXTRA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}natsort>=0:devel/py-natsort@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}imageio>=0:graphics/py-imageio@${PY_FLAVOR}

.include <bsd.port.mk>
