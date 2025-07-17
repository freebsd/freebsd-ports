PORTNAME=	internetarchive
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.1
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to archive.org
WWW=		https://github.com/jjjake/internetarchive

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.1.1:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6.0,<0.7.0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>=0.4:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0,<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schema>=0.4.0:devel/py-schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.13.0,<2.0.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.0.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR}
py39_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6.0:devel/py-importlib-metadata@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}responses>=0.20.0:devel/py-responses@${PY_FLAVOR} \
		ruff>=0.0.269:devel/ruff

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # 15 tests fail, https://github.com/jjjake/internetarchive/issues/596

USE_GITHUB=	yes
GH_ACCOUNT=	jjjake

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} PATH=${STAGEDIR}${PREFIX}/bin:${PATH}

NO_ARCH=	yes

# tests as of 5.4.1: 10 failed, 147 passed, 1 warning in 80.14s (0:01:20)

.include <bsd.port.mk>
