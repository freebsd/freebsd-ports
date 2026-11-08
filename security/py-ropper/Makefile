PORTNAME=	ropper
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.13
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Find gadgets to build rop chains for different architectures
WWW=		https://scoding.de/ropper/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>=4.0.1:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filebytes>=0.10.0:devel/py-filebytes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystone-engine>=0.9.1.3:devel/py-keystone-engine@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	sashs
GH_PROJECT=	Ropper
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETIENV} ${TEST_ENV} ${PYTHON_CMD} ./test.py)

.include <bsd.port.mk>
