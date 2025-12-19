PORTNAME=	roman-numerals
PORTVERSION=	4.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	roman_numerals-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate well-formed Roman numerals
WWW=		https://github.com/AA-Turner/roman-numerals

LICENSE=	BSD0CLAUSE CC0-1.0
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
