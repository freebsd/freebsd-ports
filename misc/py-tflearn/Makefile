PORTNAME=	tflearn
DISTVERSION=	0.3.2-53
PORTREVISION=	3
DISTVERSIONSUFFIX=	-g5c23566
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular and transparent deep learning library on top of TensorFlow
WWW=		http://tflearn.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
