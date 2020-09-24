# $FreeBSD$

PORTNAME=	ailment
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	security devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	AIL, the angr Intermediate Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}angr>=${ANGR_VERSION}:security/py-angr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}archinfo>=${ANGR_VERSION}:devel/py-archinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${ANGR_VERSION}:security/py-pyvex@${PY_FLAVOR} \
		z3>0:math/z3

USES=		gmake localbase python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
GH_TUPLE=	angr:binaries:${ANGR_BINARIES_TAGNAME}:binaries
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

pre-test:
	@${LN} -Fs ${WRKSRC_binaries} ${WRKDIR}/binaries

do-test:
	@(cd ${TEST_WRKSRC}/tests && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER})

.include "${.CURDIR}/../../security/py-angr/Makefile.version"
.include <bsd.port.mk>
