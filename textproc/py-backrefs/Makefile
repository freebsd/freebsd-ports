PORTNAME=	backrefs
DISTVERSION=	6.0.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Wrapper around re and regex that adds additional back references
WWW=		https://github.com/facelessuser/backrefs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.21.1:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS

EXTRAS_DESC=	Support for bregex (a wrapper for the external Regex library)
EXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR}

.include <bsd.port.mk>
