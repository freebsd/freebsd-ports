PORTNAME=	guessit
DISTVERSION=	3.5.0
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extract as much information as possible from a video file
WWW=		https://guessit-io.github.io/guessit/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>=0.6.0:devel/py-babelfish@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rebulk>=3.1.0:devel/py-rebulk@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
