PORTNAME=	claripy
DISTVERSIONPREFIX=	v
DISTVERSION=	9.2.219
CATEGORIES=	math devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Abstraction layer for constraint solvers
WWW=		https://github.com/angr/claripy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3-solver>=4.13.0.0:math/py-z3-solver@${PY_FLAVOR}
TEST_DEPENDS=	z3>4.8.5.0:math/z3

USES=		angr:nose python
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "BSD-2-Clause"|license = { text = "BSD-2-Clause" }|; s|77|63|g' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
