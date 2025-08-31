PORTNAME=	mmdnn
DISTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	misc python # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools to inter-operate among different deep learning frameworks
WWW=		https://github.com/microsoft/MMdnn

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.6.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	MMdnn
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
