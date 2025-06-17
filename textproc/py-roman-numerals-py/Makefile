PORTNAME=	roman-numerals-py
PORTVERSION=	3.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	roman_numerals_py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate well-formed Roman numerals
WWW=		https://github.com/AA-Turner/roman-numerals/tree/master/python \
		https://github.com/AA-Turner/roman-numerals

LICENSE=	BSD0CLAUSE CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
