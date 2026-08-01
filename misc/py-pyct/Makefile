PORTNAME=	pyct
DISTVERSION=	0.6.0
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for common tasks for users: copy examples, fetch data
WWW=		https://github.com/pyviz-dev/pyct

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.25.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.4.0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}param>=1.7.0:devel/py-param@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest

SHEBANG_FILES=	pyct/report.py

NO_ARCH=	yes

# tests as of 0.6.0: 20 passed, 1 warning in 20.37s

.include <bsd.port.mk>
