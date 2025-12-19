PORTNAME=	roman-numerals-py
PORTVERSION=	4.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	roman_numerals_py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate well-formed Roman numerals
WWW=		https://github.com/AA-Turner/roman-numerals/tree/master/python \
		https://github.com/AA-Turner/roman-numerals

LICENSE=	BSD0CLAUSE CC0-1.0
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}roman-numerals>=${PORTVERSION}<${PORTVERSION}_99:textproc/py-roman-numerals@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
