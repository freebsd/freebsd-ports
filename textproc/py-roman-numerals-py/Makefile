PORTNAME=	roman-numerals-py
DISTVERSION=	3.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	agh@riseup.net
COMMENT=	Manipulate well-formed Roman numerals
WWW=		https://pypi.org/project/roman-numerals-py/

LICENSE=	BSD0CLAUSE CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=8:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7<4:devel/py-flit-core@${PY_FLAVOR}
PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel

NO_ARCH=	yes

.include <bsd.port.mk>
