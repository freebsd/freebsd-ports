PORTNAME=	deepsearch-glm
PORTVERSION=	1.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://codeload.github.com/PeterStaar-IBM/fastText/tar.gz/9d5b2a2b364f49ed2707ff3be48a0f1ba6d86022?dummy=/:fasttext \
		https://codeload.github.com/PCRE2Project/pcre2/tar.gz/pcre2-10.44?dummy=/:pcre2 \
		https://codeload.github.com/emilk/loguru/tar.gz/4adaa185883e3c04da25913579c451d3c32cfac1?dummy=/:loguru \
		https://codeload.github.com/fmtlib/fmt/tar.gz/10.2.1?dummy=/:fmt \
		https://codeload.github.com/google/sentencepiece/tar.gz/v0.2.0?dummy=/:sentencepiece \
		https://codeload.github.com/jarro2783/cxxopts/tar.gz/v3.2.0?dummy=/:cxxopts \
		https://codeload.github.com/nemtrif/utfcpp/tar.gz/v4.0.5?dummy=/:utfcpp \
		https://codeload.github.com/nlohmann/json/tar.gz/v3.11.3?dummy=/:json
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	deepsearch_glm-${PORTVERSION}
# External dependencies from GitHub (cmake ExternalProject/FetchContent)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		PeterStaar-IBM-fastText-9d5b2a2b364f49ed2707ff3be48a0f1ba6d86022_GH0.tar.gz:fasttext \
		PCRE2Project-pcre2-pcre2-10.44_GH0.tar.gz:pcre2 \
		emilk-loguru-4adaa185883e3c04da25913579c451d3c32cfac1_GH0.tar.gz:loguru \
		fmtlib-fmt-10.2.1_GH0.tar.gz:fmt \
		google-sentencepiece-v0.2.0_GH0.tar.gz:sentencepiece \
		jarro2783-cxxopts-v3.2.0_GH0.tar.gz:cxxopts \
		nemtrif-utfcpp-v4.0.5_GH0.tar.gz:utfcpp \
		nlohmann-json-v3.11.3_GH0.tar.gz:json

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graph Language Models
WWW=		https://pypi.org/project/deepsearch-glm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 concurrent autoplist

post-extract:
	@${REINPLACE_CMD} -e 's/ resolv//g' ${WRKSRC}/cmake/os_opts.cmake
	@${REINPLACE_CMD} -e 's|^build = "build\.py"|build = "build_script.py"|' ${WRKSRC}/pyproject.toml
	@${MV} ${WRKSRC}/build.py ${WRKSRC}/build_script.py
# Extract external dependencies to locations cmake ExternalProject expects
	@${MKDIR} ${WRKSRC}/build/extlib_fasttext/src/extlib_fasttext
	@${TAR} -C ${WRKSRC}/build/extlib_fasttext/src/extlib_fasttext -xf ${DISTDIR}/PeterStaar-IBM-fastText-9d5b2a2b364f49ed2707ff3be48a0f1ba6d86022_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/extlib_pcre2/src/extlib_pcre2
	@${TAR} -C ${WRKSRC}/build/extlib_pcre2/src/extlib_pcre2 -xf ${DISTDIR}/PCRE2Project-pcre2-pcre2-10.44_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/_deps/logurugitrepo-src
	@${TAR} -C ${WRKSRC}/build/_deps/logurugitrepo-src -xf ${DISTDIR}/emilk-loguru-4adaa185883e3c04da25913579c451d3c32cfac1_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/extlib_fmt/src/extlib_fmt
	@${TAR} -C ${WRKSRC}/build/extlib_fmt/src/extlib_fmt -xf ${DISTDIR}/fmtlib-fmt-10.2.1_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/extlib_sentencepiece/src/extlib_sentencepiece
	@${TAR} -C ${WRKSRC}/build/extlib_sentencepiece/src/extlib_sentencepiece -xf ${DISTDIR}/google-sentencepiece-v0.2.0_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/extlib_cxxopts/src/extlib_cxxopts
	@${TAR} -C ${WRKSRC}/build/extlib_cxxopts/src/extlib_cxxopts -xf ${DISTDIR}/jarro2783-cxxopts-v3.2.0_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/extlib_utf8/src/extlib_utf8
	@${TAR} -C ${WRKSRC}/build/extlib_utf8/src/extlib_utf8 -xf ${DISTDIR}/nemtrif-utfcpp-v4.0.5_GH0.tar.gz --strip-components 1
	@${MKDIR} ${WRKSRC}/build/extlib_json/src/extlib_json
	@${TAR} -C ${WRKSRC}/build/extlib_json/src/extlib_json -xf ${DISTDIR}/nlohmann-json-v3.11.3_GH0.tar.gz --strip-components 1
# Patch cmake files to skip git downloads - use pre-extracted sources
	@${REINPLACE_CMD} -e '/UPDATE_COMMAND ""/d' \
		-e 's|GIT_REPOSITORY .*|DOWNLOAD_COMMAND ""|' \
		-e 's|GIT_TAG .*|UPDATE_COMMAND ""|' \
		${WRKSRC}/cmake/extlib_fmt.cmake \
		${WRKSRC}/cmake/extlib_json.cmake \
		${WRKSRC}/cmake/extlib_cxxopts.cmake \
		${WRKSRC}/cmake/extlib_pcre2.cmake \
		${WRKSRC}/cmake/extlib_fasttext.cmake \
		${WRKSRC}/cmake/extlib_utf8.git.cmake \
		${WRKSRC}/cmake/extlib_sentencepiece.cmake
# Patch loguru FetchContent to use pre-extracted source
	@${REINPLACE_CMD} -e 's|GIT_REPOSITORY .*|SOURCE_DIR "${WRKSRC}/build/_deps/logurugitrepo-src"|' \
		-e '/GIT_TAG .*/d' \
		${WRKSRC}/cmake/extlib_loguru.cmake

.include <bsd.port.mk>
