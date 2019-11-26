# $FreeBSD$

PORTNAME=	mmdnn
DISTVERSION=	0.2.5-21
DISTVERSIONSUFFIX=	-gc1c748e
CATEGORIES=	misc python # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools to inter-operate among different deep learning frameworks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>=3.1.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.6.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	MMdnn
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
