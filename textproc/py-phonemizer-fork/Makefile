PORTNAME=	phonemizer-fork
DISTVERSION=	3.3.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of phonemizer for text to phones conversion
WWW=		https://bootphon.github.io/phonemizer/ \
		https://github.com/bootphon/phonemizer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.1:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dlinfo>0:devel/py-dlinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}segments>0:textproc/py-segments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		espeak-ng>0:audio/espeak-ng \
		festival:audio/festival
TEST_DEPENDS=	festvox-kal16>0:audio/festvox-kal16

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-patch:
	# fix library path resolution in espeak api:
	@${REINPLACE_CMD} \
		-e 's|pathlib.Path(dlinfo.DLInfo(library).path)|pathlib.Path(library._name) if pathlib.Path(library._name).is_absolute() else pathlib.Path(f"${LOCALBASE}/lib/{library._name}")|' \
		${WRKSRC}/phonemizer/backend/espeak/api.py
	# set libespeak-ng.so path
	@${REINPLACE_CMD} \
		-e 's|_ESPEAK_LIBRARY = None|_ESPEAK_LIBRARY = f"${LOCALBASE}/lib/libespeak-ng.so"|' \
		${WRKSRC}/phonemizer/backend/espeak/wrapper.py
	# fix python interpreter path in tests:
	@${REINPLACE_CMD} \
		-e "s|shutil.which('python')|'${PYTHON_CMD}'|g" \
		${WRKSRC}/test/test_espeak.py \
		${WRKSRC}/test/test_festival.py
	# fix 2 assertions in tests:
	@${REINPLACE_CMD} \
		-e "s|foːɹ faɪv|fɔːɹ faɪv|g" \
		${WRKSRC}/test/test_phonemize.py
	# no no mbrola voices available on FreeBSD?
	@${REINPLACE_CMD} \
		-e "s|if sys.platform != 'win32':|if sys.platform not in ('win32', 'freebsd16', 'freebsd15', 'freebsd14', 'freebsd13'):|" \
		${WRKSRC}/test/test_espeak_wrapper.py

# tests as of 3.3.2:
# Results (10.54s):
#        582 passed
#         47 skipped
#          1 warning

.include <bsd.port.mk>
