# $FreeBSD$

PORTNAME=	ailment
DISTVERSION=	8.20.1.7
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	AIL, the angr Intermediate Language

LICENSE=	BSD2CLAUSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}angr>=${DISTVERSION}:security/py-angr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}archinfo>=${DISTVERSION}:devel/py-archinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${DISTVERSION}:security/py-pyvex@${PY_FLAVOR} \
		z3>0:math/z3

USES=		gmake localbase python
USE_GITHUB=	nodefault
GH_TUPLE=	angr:${PORTNAME}:c696edc9f31ecccaaa36b1e40ca1bed6c9715242:tests \
		angr:binaries:f2de6d7a0474d22130ffadd042327536a6fda114:binaries
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

pre-test:
	@${LN} -Fs ${WRKSRC_tests}/tests ${WRKSRC}/tests
	@${LN} -Fs ${WRKSRC_binaries} ${WRKDIR}/binaries

do-test:
	@(cd ${TEST_WRKSRC}/tests && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER})

.include <bsd.port.mk>
