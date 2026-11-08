PORTNAME=	sacremoses
DISTVERSION=	0.2.0
CATEGORIES=	textproc python # machine-learning
MASTER_SITES=	PYPI # no tests on PYPI, no latest tag in GH repo, use MASTER_SITES=PYPI here in order to keep updated, see https://github.com/hplt-project/sacremoses/issues/156
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python port of Moses tokenizer, truecaser and normalizer
WWW=		https://github.com/hplt-project/sacremoses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.2.0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2021.8.3:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.66.3:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ARGS=	--disable-plugin-autoload \
		--deselect=sacremoses/test/test_normalizer.py::TestNormalizer::test_moses_noralize_single_apostrophe

#USE_GITHUB=	yes
#GH_ACCOUNT=	hplt-project

NO_ARCH=	yes

# tests as of 0.1.1: 1 failed, 35 passed, 1 skipped in 15.70s, see https://github.com/hplt-project/sacremoses/issues/153
# 0.2.0 is not easily testable due to missing tests on PYPI and missing tag in the GH repo

.include <bsd.port.mk>
