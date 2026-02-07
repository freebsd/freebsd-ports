PORTNAME=	conway-polynomials
DISTVERSION=	0.10
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to Frank Lubeck's Conway polynomial database
WWW=		https://github.com/sagemath/conway-polynomials

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest --doctest-modules --doctest-glob='*.rst' ${WRKSRC}/README.rst ${WRKSRC}/src/conway_polynomials/__init__.py

# tests as of 0.10: 2 passed in 2.99s

.include <bsd.port.mk>
