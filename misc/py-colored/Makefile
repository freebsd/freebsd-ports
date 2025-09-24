PORTNAME=	colored
DISTVERSION=	2.3.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	timp87@gmail.com
COMMENT=	Very simple Python library for color and formatting in terminal
WWW=		https://gitlab.com/dslackw/colored

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.10.1<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
