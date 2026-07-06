PORTNAME=	rectangle-packer
DISTVERSION=	2.1.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rectangle packing library
WWW=		https://github.com/Penlect/rectangle-packer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist cython unittest

USE_GITHUB=	yes
GH_ACCOUNT=	Penlect

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/rpack/_core${PYTHON_TAG}.so

# tests as of 2.1.0: Ran 85 tests in 2.154s, OK (skipped=1)

.include <bsd.port.mk>
