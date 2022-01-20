PORTNAME=	ailment
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	security devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AIL, the angr Intermediate Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}angr>=${ANGR_VERSION}:security/py-angr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}archinfo>=${ANGR_VERSION}:devel/py-archinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${ANGR_VERSION}:security/py-pyvex@${PY_FLAVOR} \
		z3>0:math/z3

USES=		angr:binaries,nose gmake localbase python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
