PORTNAME=	ruffus
DISTVERSION=	3.0.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Lightweight library for computational pipelines
WWW=		https://github.com/cgat-developers/ruffus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	${WRKSRC}/ruffus/test/*.py

NO_ARCH=	yes

.include <bsd.port.mk>
