PORTNAME=	sentencepiece
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
CATEGORIES=	textproc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unsupervised text tokenizer for Neural Network-based text generation
WWW=		https://github.com/google/sentencepiece

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	flatc:devel/flatbuffers
LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libprotobuf-lite.so:devel/protobuf
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	google:flatbuffers:v25.12.19-2026-02-06-03fffb2:flatbuffers

CMAKE_ARGS=	-DFETCHCONTENT_SOURCE_DIR_FLATBUFFERS=${WRKSRC_flatbuffers} \
		-DSPM_ABSL_PROVIDER=package \
		-DSPM_ENABLE_LITE=OFF \
		-DSPM_FLATC_EXECUTABLE=${LOCALBASE}/bin/flatc \
		-DSPM_PROTOBUF_PROVIDER=package
CMAKE_TESTING_ON=	SPM_BUILD_TEST

# abseil 20250127+ removed absl/status/status_macros.h and
# absl/status/status_builder.h; provide local compatibility headers and
# redirect the sentencepiece includes to them.
CXXFLAGS+=	-I${WRKSRC}

post-patch:
	@${GREP} -lE '"absl/status/status_(macros|builder).h"' ${WRKSRC}/src/*.cc ${WRKSRC}/src/*.h | ${XARGS} \
		${REINPLACE_CMD} -e 's|"absl/status/status_macros.h"|"compat/absl/status/status_macros.h"|' \
			-e 's|"absl/status/status_builder.h"|"compat/absl/status/status_builder.h"|'
	@${REINPLACE_CMD} -e 's|absl::MutexLock lock(status_mutex);|absl::MutexLock lock(\&status_mutex);|' ${WRKSRC}/src/sentencepiece_processor.cc
	@${REINPLACE_CMD} -e 's|absl::MutexLock l(mu_);|absl::MutexLock l(\&mu_);|g' ${WRKSRC}/src/util.cc
	@${GREP} -l '"absl/status/status_matchers.h"' ${WRKSRC}/src/*_test.cc | ${XARGS} \
		${REINPLACE_CMD} -e 's|"absl/status/status_matchers.h"|"compat/absl/status/status_matchers.h"|'
	@${REINPLACE_CMD} -e 's|gtest gmock)|GTest::gtest GTest::gmock)|' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|absl::endian::|std::endian::|g' ${WRKSRC}/src/normalizer.cc
	@${REINPLACE_CMD} -e 's|absl::byteswap(|__builtin_bswap32(|' ${WRKSRC}/lite/sentencepiece_model_converters.h
	@${MKDIR} ${WRKSRC}/compat/absl/status
	${INSTALL_DATA} ${FILESDIR}/status_macros.h ${WRKSRC}/compat/absl/status/status_macros.h
	${INSTALL_DATA} ${FILESDIR}/status_builder.h ${WRKSRC}/compat/absl/status/status_builder.h
	${INSTALL_DATA} ${FILESDIR}/status_matchers.h ${WRKSRC}/compat/absl/status/status_matchers.h

OPTIONS_DEFINE=		GPERFTOOLS # this seems to cause this error in llama-cpp's convert_hf_to_gguf.py: Attempt to free invalid pointer 0x1ef160aa2f80, see https://github.com/google/sentencepiece/issues/1105

GPERFTOOLS_CMAKE_BOOL=	SPM_ENABLE_TCMALLOC
GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

# tests as of 0.2.3: 100% tests passed, 0 tests failed out of 1 (spm_test aggregates all unit tests)

.include <bsd.port.mk>
