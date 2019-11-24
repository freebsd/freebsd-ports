# $FreeBSD$

PORTNAME=	tflite
DISTVERSION=	g20191030
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parse TensorFlow Lite models in Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flatbuffers>0:devel/py-flatbuffers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	jackwish
GH_TAGNAME=	7814b03

NO_ARCH=	yes

.include <bsd.port.mk>
