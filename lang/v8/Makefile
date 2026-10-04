# We follow the stable channel on https://chromiumdash.appspot.com/releases?platform=Linux
# Latest stable version API: https://chromiumdash.appspot.com/fetch_releases?channel=Stable&platform=Linux&num=1&offset=0
# V8 is mirrored at https://github.com/v8/v8 (use a specific release tag, not lkgr which is a dynamic ref)
# Browse current stable branch: https://chromium.googlesource.com/v8/v8/+/refs/heads/15.4-lkgr

PORTNAME=	v8
PORTVERSION=	15.4.80.20
CATEGORIES=	lang
DIST_SUBDIR=	v8/${PORTVERSION:R}

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
GH_TUPLE=	chromium-full-mirror:external_github.com_google_cpu_features:${CPU_FEATURES_REV}:cpu_features/third_party/cpu_features/src \
		chromium-full-mirror:external_github.com_aengelke_disarm:${DISARM_REV}:disarm/third_party/disarm/src \
		chromium-full-mirror:external_github.com_jk-jeon_dragonbox:${DRAGONBOX_REV}:dragonbox/third_party/dragonbox/src \
		chromium-full-mirror:external_github.com_aengelke_fadec:${FADEC_REV}:fadec/third_party/fadec/src \
		chromium-full-mirror:external_github.com_fastfloat_fast_float:${FAST_FLOAT_REV}:fast_float/third_party/fast_float/src \
		chromium-full-mirror:external_github.com_Maratyszcza_FP16:${FP16_REV}:fp16/third_party/fp16/src \
		chromium-full-mirror:external_github.com_google_fuzztest:${FUZZTEST_SRC_REV}:fuzztest_src/third_party/fuzztest/src \
		chromium-full-mirror:external_github.com_google_googletest:${GOOGLETEST_REV}:googletest/third_party/googletest/src \
		chromium-full-mirror:external_github.com_google_highway:${HIGHWAY_REV}:highway/third_party/highway/src \
		chromium-full-mirror:external_github.com_open-source-parsers_jsoncpp:${JSONCPP_REV}:jsoncpp/third_party/jsoncpp/source \
		chromium-full-mirror:external_github.com_google_re2:${RE2_REV}:re2/third_party/re2/src \
		chromium-full-mirror:chromium_src_third_party_abseil-cpp:${ABSL_REV}:absl/third_party/abseil-cpp \
		chromium-full-mirror:chromium_src_build:${BUILD_REV}:build/build \
		chromium-full-mirror:chromium_src_buildtools:${BUILDTOOLS_REV}:buildtools/buildtools \
		chromium-full-mirror:chromium_src_tools_clang:${CLANG_REV}:clang/tools/clang \
		chromium-full-mirror:chromium_src_third_party_cpu_features:${CPU_FEATURES_CHROMIUM_REV}:cpu_features_chromium/third_party/cpu_features \
		chromium-full-mirror:chromium_src_third_party_fuzztest:${FUZZTEST_REV}:fuzztest/third_party/fuzztest \
		chromium-full-mirror:chromium_deps_icu:${ICU_REV}:icu/third_party/icu \
		chromium-full-mirror:external_github.com_llvm_llvm-project_libcxx:${LIBCXX_REV}:libcxx/third_party/libc++/src \
		chromium-full-mirror:external_github.com_llvm_llvm-project_libcxxabi:${LIBCXXABI_REV}:libcxxabi/third_party/libc++abi/src \
		chromium-full-mirror:external_github.com_llvm_llvm-project_libunwind:${LIBUNWIND_REV}:libunwind/third_party/libunwind/src \
		chromium-full-mirror:external_github.com_llvm_llvm-project_libc:${LLVM_LIBC_REV}:llvm_libc/third_party/llvm-libc/src \
		chromium-full-mirror:chromium_src_base_allocator_partition_allocator:${PARTITION_ALLOC_REV}:partition_alloc/third_party/partition_alloc \
		chromium-full-mirror:chromium_src_third_party_protobuf:${PROTOBUF_REV}:protobuf/third_party/protobuf \
		chromium-full-mirror:chromium_src_tools_protoc_wrapper:${PROTOC_WRAPPER_REV}:protoc_wrapper/tools/protoc_wrapper \
		chromium-full-mirror:chromium_src_third_party_simdutf:${SIMDUTF_REV}:simdutf/third_party/simdutf \
		chromium-full-mirror:chromium_src_third_party_zlib:${ZLIB_REV}:zlib/third_party/zlib
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

# GH_TUPLE group:path-on-chromium.googlesource.com pairs.  The distfiles come
# from the unofficial chromium-full-mirror on GitHub and are compared against
# chromium.googlesource.com by verify-mirror.  FETCH_ENV is deliberately not
# used there, as it disables TLS certificate verification.
_GS_DEPS=		absl:chromium/src/third_party/abseil-cpp \
			build:chromium/src/build \
			buildtools:chromium/src/buildtools \
			clang:chromium/src/tools/clang \
			cpu_features_chromium:chromium/src/third_party/cpu_features \
			fuzztest:chromium/src/third_party/fuzztest \
			icu:chromium/deps/icu \
			libcxx:external/github.com/llvm/llvm-project/libcxx \
			libcxxabi:external/github.com/llvm/llvm-project/libcxxabi \
			libunwind:external/github.com/llvm/llvm-project/libunwind \
			llvm_libc:external/github.com/llvm/llvm-project/libc \
			partition_alloc:chromium/src/base/allocator/partition_allocator \
			protobuf:chromium/src/third_party/protobuf \
			protoc_wrapper:chromium/src/tools/protoc_wrapper \
			simdutf:chromium/src/third_party/simdutf \
			zlib:chromium/src/third_party/zlib \
			cpu_features:external/github.com/google/cpu_features \
			disarm:external/github.com/aengelke/disarm \
			dragonbox:external/github.com/jk-jeon/dragonbox \
			fadec:external/github.com/aengelke/fadec \
			fast_float:external/github.com/fastfloat/fast_float \
			fp16:external/github.com/Maratyszcza/FP16 \
			fuzztest_src:external/github.com/google/fuzztest \
			googletest:external/github.com/google/googletest \
			highway:external/github.com/google/highway \
			jsoncpp:external/github.com/open-source-parsers/jsoncpp \
			re2:external/github.com/google/re2
# jsoncpp marks devtools/agent_vm* as eol=crlf in .gitattributes, which GitHub
# applies when generating the tarball and gitiles does not.
_GS_DIFF_ARGS_jsoncpp=	--strip-trailing-cr
_GS_SITE=		https://chromium.googlesource.com
_GS_VERIFY=		${WRKDIR}/.verify-mirror
_V8_OUTDIR=		${WRKSRC}/out/Release

# "make makesum" fetches with these two set; hook the verification in there so
# that distinfo can not be regenerated without it.
.if defined(NO_CHECKSUM) && defined(DISABLE_SIZE)
post-fetch: verify-mirror
.endif

verify-mirror:
	@${ECHO_MSG} "===>  Verifying chromium-full-mirror distfiles against ${_GS_SITE}"
.for group in \
	${GH_TUPLE:Mchromium-full-mirror\:*:C/^[^:]*:[^:]*:[^:]*:([^\/]*)\/.*/\1/}
.  if empty(_GS_DEPS:M${group}\:*)
	@${ECHO_MSG} "===>  ${group} is fetched from chromium-full-mirror but missing from _GS_DEPS"
	@${FALSE}
.  endif
.endfor
.for dep in ${_GS_DEPS}
	@${RM} -r ${_GS_VERIFY}
	@${MKDIR} ${_GS_VERIFY}/googlesource ${_GS_VERIFY}/mirror
	@${FETCH_CMD} -q \
		-o ${_GS_VERIFY}/googlesource.tar.gz \
		${_GS_SITE}/${dep:C/^[^:]*://}/+archive/${GH_TAGNAME_${dep:C/:.*//}}.tar.gz
	@${TAR} -xf ${_GS_VERIFY}/googlesource.tar.gz \
		-C ${_GS_VERIFY}/googlesource
	@${TAR} -xf ${_DISTDIR}/${DISTFILE_${dep:C/:.*//}} --strip-components 1 \
		-C ${_GS_VERIFY}/mirror
	@cd ${_GS_VERIFY}/googlesource && ${FIND} . ! -type l -exec ${STAT} -f '%HT %Lp %N' {} + | \
		LC_ALL=C ${SORT} > ${_GS_VERIFY}/googlesource.list
	@cd ${_GS_VERIFY}/mirror && ${FIND} . ! -type l -exec ${STAT} -f '%HT %Lp %N' {} + | \
		LC_ALL=C ${SORT} > ${_GS_VERIFY}/mirror.list
	@if ! ${DIFF} -u ${_GS_VERIFY}/googlesource.list ${_GS_VERIFY}/mirror.list || \
		! ${DIFF} -r --no-dereference ${_GS_DIFF_ARGS_${dep:C/:.*//}} ${_GS_VERIFY}/googlesource ${_GS_VERIFY}/mirror; then \
		${ECHO_MSG} "===>  MISMATCH: ${DISTFILE_${dep:C/:.*//}} differs from ${_GS_SITE}/${dep:C/^[^:]*://}"; \
		${ECHO_MSG} "===>  Do NOT update distinfo or commit."; \
		${FALSE}; \
	fi
	@${ECHO_MSG} "=> ${dep:C/:.*//} ${GH_TAGNAME_${dep:C/:.*//}} identical"
.endfor
	@${RM} -r ${_GS_VERIFY}
	@${ECHO_MSG} "===>  verify-mirror: all ${_GS_DEPS:[#]} mirrored distfiles match ${_GS_SITE}"

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
