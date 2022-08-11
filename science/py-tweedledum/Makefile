PORTNAME=	tweedledum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for analysis, compilation, synthesis of quantum circuits

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265751

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		cmake:devel/cmake

USES=		compiler:c++17-lang python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/boschmitt/tweedledum/issues/176

USE_GITHUB=	yes
GH_ACCOUNT=	boschmitt

.include <bsd.port.mk>
