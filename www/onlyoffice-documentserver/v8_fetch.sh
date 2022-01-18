#!/bin/sh

BUILD_REV=38a49c12ded01dd8c4628b432cb7eebfb29e77f1
BUILDTOOLS_REV=3ff4f5027b4b81a6c9c36d64d71444f2709a4896
CLANG_REV=3017edade60658a699be776d9e282509a902ffe9
COMMON_REV=23ef5333a357fc7314630ef88b44c3a545881dee
GOOGLETEST_REV=4fe018038f87675c083d0cfb6a6b57c274fb1753
ICU_REV=aef20f06d47ba76fdf13abcdb033e2a408b5a94d
ZLIB_REV=4668feaaa47973a6f9d9f9caeb14cd03731854f1
V8_VERS=8.7.220.31

TAR=tar
MV=mv
MKDIR=mkdir
FETCH_CMD=fetch
WRKSRC=v8
DISTDIR=/usr/ports/distfiles
ECHO=echo
RM=rm

${FETCH_CMD} -o ${DISTDIR}/build-${BUILD_REV}.tar.gz \
	https://chromium.googlesource.com/chromium/src/build.git/+archive/${BUILD_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/buildtools-${BUILDTOOLS_REV}.tar.gz \
	https://chromium.googlesource.com/chromium/src/buildtools.git/+archive/${BUILDTOOLS_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/clang-${CLANG_REV}.tar.gz \
	https://chromium.googlesource.com/chromium/src/tools/clang.git/+archive/${CLANG_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/common-${COMMON_REV}.tar.gz \
	https://chromium.googlesource.com/chromium/src/base/trace_event/common.git/+archive/${COMMON_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/googletest-${GOOGLETEST_REV}.tar.gz \
	https://chromium.googlesource.com/external/github.com/google/googletest.git/+archive/${GOOGLETEST_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/icu-${ICU_REV}.tar.gz \
	https://chromium.googlesource.com/chromium/deps/icu.git/+archive/${ICU_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/zlib-${ZLIB_REV}.tar.gz \
	https://chromium.googlesource.com/chromium/src/third_party/zlib.git/+archive/${ZLIB_REV}.tar.gz
${FETCH_CMD} -o ${DISTDIR}/v8-${V8_VERS}.tar.gz https://github.com/archive/refs/tags/${V8_VERS}.tar.gz

${RM} -rf ${WRKSRC}
${TAR} -xf ${DISTDIR}/v8-${V8_VERS}.tar.gz
${MV} v8-${V8_VERS} ${WRKSRC}
${MKDIR} -p ${WRKSRC}/build \
	${WRKSRC}/buildtools \
	${WRKSRC}/tools/clang \
	${WRKSRC}/base/trace_event/common \
	${WRKSRC}/third_party/icu \
	${WRKSRC}/third_party/zlib \
	${WRKSRC}/third_party/googletest/src
${TAR} -xf ${DISTDIR}/build-${BUILD_REV}.tar.gz -C ${WRKSRC}/build
${TAR} -xf ${DISTDIR}/buildtools-${BUILDTOOLS_REV}.tar.gz -C ${WRKSRC}/buildtools
${TAR} -xf ${DISTDIR}/clang-${CLANG_REV}.tar.gz -C ${WRKSRC}/tools/clang
${TAR} -xf ${DISTDIR}/common-${COMMON_REV}.tar.gz -C ${WRKSRC}/base/trace_event/common
${TAR} -xf ${DISTDIR}/googletest-${GOOGLETEST_REV}.tar.gz -C ${WRKSRC}/third_party/googletest/src
${TAR} -xf ${DISTDIR}/icu-${ICU_REV}.tar.gz -C ${WRKSRC}/third_party/icu
${TAR} -xf ${DISTDIR}/zlib-${ZLIB_REV}.tar.gz -C ${WRKSRC}/third_party/zlib

# google sucks, this file is needed but absent in the build* archive
# https://github.com/klzgrad/naiveproxy/blob/master/src/build/config/gclient_args.gni
${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/build/config/gclient_args.gni

${TAR} -cf v8-${V8_VERS}_all.tar.gz v8
