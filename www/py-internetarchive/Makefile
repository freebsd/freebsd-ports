PORTNAME=	internetarchive
DISTVERSIONPREFIX=	v
DISTVERSION=	5.12.0
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to archive.org
WWW=		https://github.com/jjjake/internetarchive

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpatch>=0.4:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.0.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}responses>=0.20.0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.0.269:devel/py-ruff@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest

SHEBANG_FILES=	internetarchive/cli/ia.py

USE_GITHUB=	yes
GH_ACCOUNT=	jjjake

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH}
TEST_ARGS=	--disable-plugin-autoload \
		-p responses -p ruff

NO_ARCH=	yes

post-patch:
	@${ECHO_CMD} '__version__ = "${DISTVERSION}"' > ${WRKSRC}/internetarchive/_version.py

# tests as of 5.12.0: 352 passed, 37 skipped, 3 warnings in 35.50s

.include <bsd.port.mk>
