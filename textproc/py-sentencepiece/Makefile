PORTNAME=	sentencepiece
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
CATEGORIES=	textproc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unsupervised text tokenizer for Neural Network-based text generation
WWW=		https://github.com/google/sentencepiece

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=2.13:devel/py-pybind11@${PY_FLAVOR} \
		flatc:devel/flatbuffers \
		protoc:devel/protobuf
LIB_DEPENDS=	libsentencepiece.so:textproc/sentencepiece
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}

USES=		compiler:c++17-lang pkgconfig python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	google

WRKSRC_SUBDIR=	python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

post-patch:
	@${REINPLACE_CMD} -e 's|absl::byteswap(|__builtin_bswap32(|' ${WRKSRC}/../lite/sentencepiece_model_converters.h
	@${REINPLACE_CMD} -E -e 's|absl::MutexLock ([a-z_]+)\(([a-z_]+)\)|absl::MutexLock \1(\&\2)|' ${WRKSRC}/src/sentencepiece/sentencepiece_pybind.cc

pre-build:
	@${MKDIR} ${WRKSRC}/gen
	${LOCALBASE}/bin/protoc --cpp_out=${WRKSRC}/gen -I${WRKSRC}/../src ${WRKSRC}/../src/sentencepiece_model.proto
	${LOCALBASE}/bin/flatc -c --gen-object-api -o ${WRKSRC}/gen ${WRKSRC}/../lite/sentencepiece_lite.fbs

# tests as of 0.2.3: 78 passed, 0 failed

.include <bsd.port.mk>
