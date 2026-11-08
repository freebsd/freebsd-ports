PORTNAME=	latex2mathml
PORTVERSION=	3.81.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Python library for LaTeX to MathML conversion
WWW=		https://github.com/roniemartinez/latex2mathml

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.mk>
