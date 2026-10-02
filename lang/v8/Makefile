# We follow the stable channel on https://chromiumdash.appspot.com/releases?platform=Linux
# Latest stable version API: https://chromiumdash.appspot.com/fetch_releases?channel=Stable&platform=Linux&num=1&offset=0
# V8 is mirrored at https://github.com/v8/v8 (use a specific release tag, not lkgr which is a dynamic ref)
# Browse current stable branch: https://chromium.googlesource.com/v8/v8/+/refs/heads/15.4-lkgr

PORTNAME=	v8
PORTVERSION=	15.4.80.20
CATEGORIES=	lang
# Sub-dependencies are fetched from chromium.googlesource.com +archive endpoint
# (archives extract flat with no top-level wrapper directory)
MASTER_SITES+=	https://chromium.googlesource.com/chromium/src/third_party/abseil-cpp/+archive/:absl \
		https://chromium.googlesource.com/chromium/src/build/+archive/:build \
		https://chromium.googlesource.com/chromium/src/buildtools/+archive/:buildtools \
		https://chromium.googlesource.com/chromium/src/tools/clang/+archive/:clang \
		https://chromium.googlesource.com/chromium/src/third_party/cpu_features/+archive/:cpu_features_chromium \
		https://chromium.googlesource.com/external/github.com/google/cpu_features/+archive/:cpu_features \
		https://chromium.googlesource.com/external/github.com/aengelke/disarm/+archive/:disarm \
		https://chromium.googlesource.com/external/github.com/jk-jeon/dragonbox/+archive/:dragonbox \
		https://chromium.googlesource.com/external/github.com/aengelke/fadec/+archive/:fadec \
		https://chromium.googlesource.com/external/github.com/fastfloat/fast_float/+archive/:fast_float \
		https://chromium.googlesource.com/external/github.com/Maratyszcza/FP16/+archive/:fp16 \
		https://chromium.googlesource.com/chromium/src/third_party/fuzztest/+archive/:fuzztest \
		https://chromium.googlesource.com/external/github.com/google/fuzztest/+archive/:fuzztest_src \
		https://chromium.googlesource.com/external/github.com/google/googletest/+archive/:googletest \
		https://chromium.googlesource.com/external/github.com/google/highway/+archive/:highway \
		https://chromium.googlesource.com/chromium/deps/icu/+archive/:icu \
		https://chromium.googlesource.com/external/github.com/open-source-parsers/jsoncpp/+archive/:jsoncpp \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxx/+archive/:libcxx \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxxabi/+archive/:libcxxabi \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libunwind/+archive/:libunwind \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libc/+archive/:llvm_libc \
		https://chromium.googlesource.com/chromium/src/base/allocator/partition_allocator/+archive/:partition_alloc \
		https://chromium.googlesource.com/chromium/src/third_party/protobuf/+archive/:protobuf \
		https://chromium.googlesource.com/chromium/src/tools/protoc_wrapper/+archive/:protoc_wrapper \
		https://chromium.googlesource.com/external/github.com/google/re2/+archive/:re2 \
		https://chromium.googlesource.com/chromium/src/third_party/simdutf/+archive/:simdutf \
		https://chromium.googlesource.com/chromium/src/third_party/zlib/+archive/:zlib
DISTFILES=	${ABSL_REV}.tar.gz:absl \
		${BUILD_REV}.tar.gz:build \
		${BUILDTOOLS_REV}.tar.gz:buildtools \
		${CLANG_REV}.tar.gz:clang \
		${CPU_FEATURES_CHROMIUM_REV}.tar.gz:cpu_features_chromium \
		${CPU_FEATURES_REV}.tar.gz:cpu_features \
		${DISARM_REV}.tar.gz:disarm \
		${DRAGONBOX_REV}.tar.gz:dragonbox \
		${FADEC_REV}.tar.gz:fadec \
		${FAST_FLOAT_REV}.tar.gz:fast_float \
		${FP16_REV}.tar.gz:fp16 \
		${FUZZTEST_REV}.tar.gz:fuzztest \
		${FUZZTEST_SRC_REV}.tar.gz:fuzztest_src \
		${GOOGLETEST_REV}.tar.gz:googletest \
		${HIGHWAY_REV}.tar.gz:highway \
		${ICU_REV}.tar.gz:icu \
		${JSONCPP_REV}.tar.gz:jsoncpp \
		${LIBCXX_REV}.tar.gz:libcxx \
		${LIBCXXABI_REV}.tar.gz:libcxxabi \
		${LIBUNWIND_REV}.tar.gz:libunwind \
		${LLVM_LIBC_REV}.tar.gz:llvm_libc \
		${PARTITION_ALLOC_REV}.tar.gz:partition_alloc \
		${PROTOBUF_REV}.tar.gz:protobuf \
		${PROTOC_WRAPPER_REV}.tar.gz:protoc_wrapper \
		${RE2_REV}.tar.gz:re2 \
		${SIMDUTF_REV}.tar.gz:simdutf \
		${ZLIB_REV}.tar.gz:zlib
DIST_SUBDIR=	v8/${PORTVERSION:R}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google
WWW=		https://v8.dev/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		binutils>=0:devel/binutils \
		gn:devel/gn
LIB_DEPENDS=	libicudata.so:devel/icu

USES=		compiler:c++20-lang cpe elfctl gnome llvm:min=20,build ninja \
		pkgconfig python:build
CPE_VENDOR=	google
USE_GITHUB=	yes
GH_ACCOUNT=	v8
GH_PROJECT=	v8
USE_GNOME=	glib20
USE_LDCONFIG=	yes

MAKE_ARGS=	-C \
		out/Release
ALL_TARGET=	d8 v8_shell mkgrokdump mksnapshot
# V8's JIT maps its code range read+write+execute and has no W^X mode usable
# on FreeBSD, so isolate creation aborts when kern.elf64.allow_wx=0
# (PR 271838).  The kernel reads wxneeded from the main executable only, so
# consumers embedding libv8 must mark their own binaries the same way.
ELF_FEATURES=	+wxneeded:out/Release/d8 +wxneeded:out/Release/mkgrokdump \
		+wxneeded:out/Release/mksnapshot +wxneeded:out/Release/v8_shell

CONFLICTS_INSTALL=	v8-beta

BINARY_ALIAS=	python3=${PYTHON_CMD}
SUB_FILES=	v8.pc v8_libbase.pc v8_libplatform.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

# Sub-dependency commit hashes from DEPS at tag ${PORTVERSION}
ABSL_REV=			435e7d977fb36fb47854a4c552c0706dad0bd7cf
BUILD_REV=			fdd530b37c6cd6c8645cdfa296d209643ab2dc26
BUILDTOOLS_REV=			6f6a5dbf04b734214f3b1f386567d101ec9d607e
CLANG_REV=			450d823868eaee61e2b2cb986e19aec287f16d58
CPU_FEATURES_CHROMIUM_REV=	4974e2063946d9dd2a417c27db139fd982ff447a
CPU_FEATURES_REV=		81d13c49649f0714dd41fb56bb246398b6584085
DISARM_REV=			2d13d3f410a52daff1c5d8ef07d623332f372560
DRAGONBOX_REV=			beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44
FADEC_REV=			c9f78f532b9004de278489019ab2c6c28ae9746e
FAST_FLOAT_REV=			34164f547b7df3f5d794ff67e9f885c36819ebfc
FP16_REV=			782eea126dc5c755827be751a099eb01826175cf
FUZZTEST_REV=			0dcd0b87a3252a116ec59fadcfc80f2d2015bbac
FUZZTEST_SRC_REV=		94c3cf3a4391eb0bb12999128e29cbe625bad2f3
GOOGLETEST_REV=			4fe3307fb2d9f86d19777c7eb0e4809e9694dde7
HIGHWAY_REV=			2607d3b5b0113992fe84d3848859eae13b3b52c1
ICU_REV=			8cc91d9b6ab9991802fd208ee03a69714fd0251c
JSONCPP_REV=			3347a4b86bb914cb565f0cbda19c06e109513300
LIBCXX_REV=			97b436da4c33663581d394f4ee0a5977fc38c2f4
LIBCXXABI_REV=			fc1897a2c12aa27e703c3ed48b62eba8abf4ce19
LIBUNWIND_REV=			45120ee2331193c3650acc9c427ed267fab31d62
LLVM_LIBC_REV=			320824188c37e5c28738b9652a0ca8087c934bc9
PARTITION_ALLOC_REV=		f0d1e646eb41d8736261d5d8d8f094404bac62ac
PROTOBUF_REV=			5f8c379d1fc89fe8eee16ae560dd5e514a4608da
PROTOC_WRAPPER_REV=		e9dbe1bf6a2a5d2d4973725874259eed587cf18d
RE2_REV=			972a15cedd008d846f1a39b2e88ce48d7f166cbd
SIMDUTF_REV=			f7356eed293f8208c40b3c1b344a50bd70971983
ZLIB_REV=			5eb4d7ed380f214e7a0a23c18f629048d3ba9e00

# Run "gn args --list out/Release" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	clang_base_path="${LLVM_PREFIX}" \
		clang_use_chrome_plugins=false \
		enable_rust=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS} -Wl,--icf=none" \
		is_clang=true \
		icu_use_data_file=false \
		is_component_build=true \
		is_debug=false \
		treat_warnings_as_errors=false \
		use_aura=true \
		use_lld=true \
		use_custom_libcxx=false \
		use_custom_libcxx_for_host=false \
		v8_use_external_startup_data=false \
		v8_enable_temporal_support=false # TC39 Temporal (Stage 3) requires Rust; disabled until supported

#OPTIONS_DEFINE=	EXAMPLES

# rev:dest-subdir-under-WRKSRC pairs for sub-dependency extraction
_V8_OUTDIR=	${WRKSRC}/out/Release

post-extract:
.for dep in ${ABSL_REV}:third_party/abseil-cpp ${BUILD_REV}:build \
	${BUILDTOOLS_REV}:buildtools ${CLANG_REV}:tools/clang \
	${CPU_FEATURES_CHROMIUM_REV}:third_party/cpu_features \
	${CPU_FEATURES_REV}:third_party/cpu_features/src \
	${DISARM_REV}:third_party/disarm/src \
	${DRAGONBOX_REV}:third_party/dragonbox/src \
	${FADEC_REV}:third_party/fadec/src \
	${FAST_FLOAT_REV}:third_party/fast_float/src \
	${FP16_REV}:third_party/fp16/src ${FUZZTEST_REV}:third_party/fuzztest \
	${FUZZTEST_SRC_REV}:third_party/fuzztest/src \
	${GOOGLETEST_REV}:third_party/googletest/src \
	${HIGHWAY_REV}:third_party/highway/src ${ICU_REV}:third_party/icu \
	${JSONCPP_REV}:third_party/jsoncpp/source \
	${LIBCXX_REV}:third_party/libc++/src \
	${LIBCXXABI_REV}:third_party/libc++abi/src \
	${LIBUNWIND_REV}:third_party/libunwind/src \
	${LLVM_LIBC_REV}:third_party/llvm-libc/src \
	${PARTITION_ALLOC_REV}:third_party/partition_alloc \
	${PROTOBUF_REV}:third_party/protobuf \
	${PROTOC_WRAPPER_REV}:tools/protoc_wrapper \
	${RE2_REV}:third_party/re2/src ${SIMDUTF_REV}:third_party/simdutf \
	${ZLIB_REV}:third_party/zlib
	@${MKDIR} ${WRKSRC}/${dep:C/.*://}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${dep:C/:.*//}.tar.gz -C ${WRKSRC}/${dep:C/.*://}
.endfor

post-patch:
	@${REINPLACE_CMD} -i '' 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/build/toolchain/gcc_toolchain.gni
# https://github.com/klzgrad/naiveproxy/blob/master/src/build/config/gclient_args.gni
	@${ECHO_CMD} 'checkout_google_benchmark = false' > ${WRKSRC}/build/config/gclient_args.gni

# Use ICU from ports and create needed directory
pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} ./build/linux/unbundle/replace_gn_files.py --system-libraries icu # || ${FALSE}
	@${MKDIR} ${_V8_OUTDIR}/gen/shim_headers/icui18n_shim/third_party/icu/source/i18n/unicode \
		${_V8_OUTDIR}/gen/shim_headers/icuuc_shim/third_party/icu/source/common/unicode \
		${_V8_OUTDIR}/gen/include
	@${CP} -R ${LOCALBASE}/include/unicode ${_V8_OUTDIR}/gen/include/unicode

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen out/Release --args='${GN_ARGS}'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cppgc ${STAGEDIR}${PREFIX}/include/libplatform
.for prog in d8 mkgrokdump mksnapshot v8_shell
	${INSTALL_PROGRAM} ${_V8_OUTDIR}/${prog} ${STAGEDIR}${PREFIX}/bin/${prog}
.endfor
.for lib in libchrome_zlib.so libv8.so libv8_libbase.so libv8_libplatform.so \
	libthird_party_abseil-cpp_absl.so \
	libthird_party_partition_alloc_src_partition_alloc_allocator_base.so \
	libthird_party_partition_alloc_src_partition_alloc_allocator_core.so \
	libthird_party_partition_alloc_src_partition_alloc_allocator_shim.so
	${INSTALL_LIB} ${_V8_OUTDIR}/${lib} ${STAGEDIR}${PREFIX}/lib/${lib}
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/
	cd ${WRKSRC}/include/cppgc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/cppgc '-name *\.h'
	${INSTALL_DATA} ${WRKSRC}/include/libplatform/*.h ${STAGEDIR}${PREFIX}/include/libplatform/
	${INSTALL_DATA} ${WRKDIR}/v8*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${_V8_OUTDIR}/v8_simple_* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
