PORTNAME=	pyct
DISTVERSION=	0.4.8
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for common tasks for users: copy examples, fetch data
WWW=		https://github.com/pyviz-dev/pyct

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}param>=1.7.0:devel/py-param@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
