PORTNAME=	phonemizer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
CATEGORIES=	textproc python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple text to phones converter for multiple languages
WWW=		https://bootphon.github.io/phonemizer/ \
		https://github.com/bootphon/phonemizer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.1:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dlinfo>0:devel/py-dlinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}segments>0:textproc/py-segments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		espeak-ng>0:audio/espeak-ng \
		festival:audio/festival
TEST_DEPENDS=	festvox-kal8>0:audio/festvox-kal8

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	bootphon

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-k "not test_path_bad and not test_path_venv" # these 2 fail because we manipulate the env var

BINARY_ALIAS=	python=${PYTHON_CMD} # only for tests

NO_ARCH=	yes

post-patch:
	# substitute %%LIBRARY%% with constant library path
	@${REINPLACE_CMD} -i '' -e "s|%%LIBRARY%%|${LOCALBASE}/lib/libespeak-ng.so|g" \
		${WRKSRC}/phonemizer/backend/espeak/wrapper.py

# tests as of 3.4.0: 2 failed, 199 passed, 43 skipped, 4 deselected in 8.49s, see https://github.com/bootphon/phonemizer/issues/221

.include <bsd.port.mk>
