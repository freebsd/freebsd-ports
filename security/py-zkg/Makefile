PORTNAME=	zkg
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mshirk@daemon-security.com
COMMENT=	Zeek NSM package manager
WWW=		https://github.com/zeek/package-manager

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}btest>=1.2:devel/py-btest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.43:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.10.0:devel/py-semantic-version@${PY_FLAVOR} \
		git:devel/git
TEST_DEPENDS=	zeek>=0:security/zeek

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	zeek
GH_PROJECT=	package-manager
USE_PYTHON=	autoplist concurrent pep517

# Only required for testing
.if make(test)
BINARY_ALIAS=	python3=${PYTHON_CMD}
.endif

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/testing && ${SETENV} ${TEST_ENV} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		btest -A -c btest.cfg

.include <bsd.port.mk>
