PORTNAME=	periodictable
DISTVERSION=	1.7.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extensible periodic table of the elements pre-populated with data
WWW=		https://periodictable.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 3 tests fail, see https://github.com/pkienzle/periodictable/issues/84

NO_ARCH=	yes

.include <bsd.port.mk>
