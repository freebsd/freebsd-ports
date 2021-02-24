# $FreeBSD$

PORTNAME=	ropper
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.6
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Find gadgets to build rop chains for different architectures

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>=4.0.1:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filebytes>=0.10.0:devel/py-filebytes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystone-engine>=0.9.1.3:devel/py-keystone-engine@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	sashs
GH_PROJECT=	Ropper
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./test.py)

.include <bsd.port.mk>
