PORTNAME=	libtensorflow1
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.5
DISTVERSIONSUFFIX=
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	freebsd-ports@otoh.org
COMMENT=	C API for TensorFlow, an open source platform for machine learning

LICENSE=	APACHE20 THIRD_PARTY_TF_C_LICENSES
LICENSE_COMB=	multi
LICENSE_NAME_THIRD_PARTY_TF_C_LICENSES=	Third-Party TensorFlow C Licenses
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_THIRD_PARTY_TF_C_LICENSES=	${WRKDIR}/THIRD_PARTY_TF_C_LICENSES
LICENSE_PERMS_THIRD_PARTY_TF_C_LICENSES=	dist-mirror dist-sell \
						pkg-mirror pkg-sell auto-accept

BROKEN=		does not build: tries to fetch during the build
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		bazel029<1:devel/bazel029 \
		git:devel/git

FLAVORS=	default noavx
FLAVOR?=	${FLAVORS:[1]}
noavx_PKGNAMESUFFIX=	-noavx
noavx_CONFLICTS_INSTALL=	libtensorflow1
default_CONFLICTS_INSTALL=	libtensorflow1-noavx
CONFLICTS_INSTALL=	science/libtensorflow2

USES=		gmake python:3.7-3.9,build

USE_GITHUB=	yes
GH_ACCOUNT=	tensorflow
GH_PROJECT=	tensorflow
GH_TUPLE=	bazelbuild:rules_closure:308b05b2:bazelbuild_rules_closure \
		intel:mkl-dnn:v0.20.6:intel_mkl_dnn_0 \
		intel:mkl-dnn:v1.0-pc2:intel_mkl_dnn_1 \
		abseil:abseil-cpp:43ef2148c0936ebf7cb4be6b19927a9d9d145b8f:abseil_abseil_cpp \
		rvagg:rpi-newer-crosstools:eb68350c5c8ec1663b7fe52c742ac4271e3217c5:rvagg_rpi_newer_crosstools \
		hfp:libxsmm:1.11:hfp_libxsmm \
		google:re2:506cfa4bffd060c06ec338ce50ea3468daa6c814:google_re2 \
		googleapis:google-cloud-cpp:v0.10.0:googleapis_google_cloud_cpp \
		googleapis:googleapis:f81082ea1e2f85c43649bee26e0d9871d4b41cdb:googleapis_googleapis \
		google:gemmlowp:12fed0cd7cfcd9e169bf1925bc3a7a58725fdcc3:google_gemmlowp \
		google:farmhash:816a4ae622e964763ca0862d9dbd19324a1eaf45:google_farmhash \
		glennrp:libpng:v1.6.37:glennrp_libpng \
		abseil:abseil-py:pypi-v0.7.1:abseil_abseil_py \
		protocolbuffers:protobuf:310ba5ee72661c081129eb878c1bbcec936b20f0:protocolbuffers_protobuf \
		google:nsync:1.22.0:google_nsync \
		google:googletest:b6cd405286ed8635ece71c72f118e659f4ade3fb:google_googletest \
		gflags:gflags:v2.2.1:gflags_gflags \
		grpc:grpc:4566c2a29ebec0835643b972eb99f4306c4234a3:grpc_grpc \
		nanopb:nanopb:f8ac463766281625ad710900479130c7fcb4d63b:nanopb_nanopb \
		antirez:linenoise:c894b9e59f02203dbe4e2be657572cf88c4230c3:antirez_linenoise \
		llvm-mirror:llvm:7a7e03f906aada0cf4b749b51213fe5784eeff84:llvm_mirror_llvm \
		LMDB:lmdb:LMDB_0.9.22:LMDB_lmdb \
		open-source-parsers:jsoncpp:1.8.4:open_source_parsers_jsoncpp \
		google:boringssl:7f634429a04abc48e2eb041c81c5235816c96514:google_boringssl \
		google:snappy:1.1.7:google_snappy \
		nvidia:nccl:0ceaec9cee96ae7658aa45686853286651f36384:nvidia_nccl \
		edenhill:librdkafka:v0.11.5:edenhill_librdkafka \
		google:pprof:c0fb62ec88c411cc91194465e54db2632845b650:google_pprof \
		NVlabs:cub:1.8.0:NVlabs_cub \
		ROCmSoftwarePlatform:rocPRIM:4a33d328f8352df1654271939da66914f2334424:ROCmSoftwarePlatform_rocPRIM \
		cython:cython:0.28.4:cython_cython \
		intel:ARM_NEON_2_x86_SSE:1200fe90bb174a6224a525ee60148671a786a71f:intel_ARM_NEON_2_x86_SSE \
		google:double-conversion:3992066a95b823efc8ccc1baf82a1cfc73f6e9b8:google_double_conversion \
		bazelbuild:rules_android:v0.1.1:bazelbuild_rules_android \
		01org:tbb:2019_U1:01org_tbb \
		NervanaSystems:ngraph:v0.11.0:NervanaSystems_ngraph \
		nlohmann:json:v3.4.0:nlohmann_json \
		NervanaSystems:ngraph-tf:v0.9.0:NervanaSystems_ngraph_tf \
		pybind:pybind11:v2.3.0:pybind_pybind11 \
		GrahamDumpleton:wrapt:1.11.1:GrahamDumpleton_wrapt

USE_LDCONFIG=	yes

CC?=		clang

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

SOVERSION=	${DISTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=	CUDA OPENCL_SYCL ROCM XLA
OPTIONS_DEFAULT=	AVX

OPTIONS_SINGLE=			CPUFEATURE
OPTIONS_SINGLE_CPUFEATURE=	AVX AVX2 NOAVX
.if ${FLAVOR:U} == noavx
OPTIONS_EXCLUDE:=	${OPTIONS_SINGLE_CPUFEATURE}
.endif

CPUFEATURE_DESC=Vector Processing Extensions

NOAVX_DESC=	Disable Advanced Vector Extensions
AVX_DESC=	Enable Advanced Vector Extensions (AVX)
AVX2_DESC=	Enable Advanced Vector Extensions v2 (AVX2)

NOAVX_VARS=	BAZEL_ARGS=""
AVX_VARS=	BAZEL_ARGS="--copt=-march=core-avx-i --host_copt=-march=core-avx-i"
AVX2_VARS=	BAZEL_ARGS="--copt=-march=core-avx2 --host_copt=-march=core-avx2"

CUDA_DESC=	Enable Compute Unified Device Architecture (CUDA) for Nvidia GPUs
CUDA_VARS=	TF_ENABLE_CUDA=1
CUDA_VARS_OFF=	TF_ENABLE_CUDA=0

OPENCL_SYCL_DESC=	Enable OpenCL Sycl
OPENCL_SYCL_VARS=	TF_NEED_OPENCL_SYCL=1
OPENCL_SYCL_VARS_OFF=	TF_NEED_OPENCL_SYCL=0

ROCM_DESC=	Enable Radeon Open Computer (ROCm) for AMD GPUs
ROCM_VARS=	TF_ENABLE_ROCM=1
ROCM_VARS_OFF=	TF_ENABLE_ROCM=0

XLA_DESC=	Enable Accelerated Linear Algebra (XLA)
XLA_VARS=	TF_ENABLE_XLA=1
XLA_VARS_OFF=	TF_ENABLE_XLA=0

BAZEL_OPTS=	--output_user_root=${WRKDIR}/bazel_out

.include <bsd.port.options.mk>
.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1200000 && ${OSVERSION} < 1300000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-third_party_repo.bzl
.endif

post-extract:
# THIRD_PARTY_TF_C_LICENSES is generated as a Bazel build target (see
# //tensorflow/tools/lib_package:clicenses) and the empty file written
# here will be overwritten. Creation of this file is to satisfy checks.
	@${TOUCH} ${WRKDIR}/THIRD_PARTY_TF_C_LICENSES

post-patch:
	${REINPLACE_CMD} -e 's,%%PYTHON_CMD%%,${PYTHON_CMD},' \
			-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/.bazelrc

do-configure:
	@cd ${WRKSRC} && ${SETENV} \
	  CC_OPT_FLAGS="-I${LOCALBASE}/include" \
	  PREFIX="${LOCALBASE}" \
	  PYTHON_BIN_PATH=${PYTHON_CMD} \
	  PYTHON_LIB_PATH="${PYTHON_SITELIBDIR}" \
	  TF_CONFIGURE_IOS=0 \
	  TF_DOWNLOAD_CLANG=0 \
	  TF_NEED_OPENCL_SYCL=${TF_NEED_OPENCL_SYCL} \
	  TF_ENABLE_XLA=${TF_ENABLE_XLA} \
	  TF_IGNORE_MAX_BAZEL_VERSION=0 \
	  TF_NEED_CUDA=${TF_ENABLE_CUDA} \
	  TF_NEED_MPI=0 \
	  TF_NEED_ROCM=${TF_ENABLE_ROCM} \
	  TF_NEED_TENSORRT=0 \
	  TF_SET_ANDROID_WORKSPACE=0 \
	  ${LOCALBASE}/bin/bash ./configure

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/bazel ${BAZEL_OPTS} build \
	  ${BAZEL_ARGS} \
	  --action_env=PATH=${PATH} \
	  --discard_analysis_cache \
	  --local_cpu_resources=${MAKE_JOBS_NUMBER} \
	  --nokeep_state_after_build \
	  --noshow_loading_progress \
	  --noshow_progress \
	  --notrack_incremental_state \
	  --subcommands \
	  --verbose_failures \
	  //tensorflow/tools/lib_package:clicenses_generate \
	  //tensorflow/tools/lib_package:libtensorflow.tar.gz

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/bazel ${BAZEL_OPTS} test \
	  ${BAZEL_ARGS} \
	  --action_env=PATH=${PATH} \
	  --discard_analysis_cache \
	  --local_cpu_resources=${MAKE_JOBS_NUMBER} \
	  --nokeep_state_after_build \
	  --noshow_loading_progress \
	  --noshow_progress \
	  --notrack_incremental_state \
	  --subcommands \
	  --test_env=CC=${CC} \
	  --verbose_failures \
	  //tensorflow/tools/lib_package:libtensorflow_test

pre-install:
	${CP} ${WRKSRC}/bazel-bin/tensorflow/tools/lib_package/THIRD_PARTY_TF_C_LICENSES \
	  ${WRKDIR}/THIRD_PARTY_TF_C_LICENSES
	${MKDIR} ${WRKDIR}/lib_package
	(cd ${WRKDIR}/lib_package && ${TAR} xvf \
	  ${WRKSRC}/bazel-bin/tensorflow/tools/lib_package/libtensorflow.tar.gz)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tensorflow/c/eager

do-install:
.for f in c_api_experimental.h c_api.h eager/c_api.h \
	tf_attrtype.h tf_datatype.h tf_status.h tf_tensor.h
	${INSTALL_DATA} ${WRKDIR}/lib_package/include/tensorflow/c/${f} \
	  ${STAGEDIR}${PREFIX}/include/tensorflow/c/${f}
.endfor
.for l in libtensorflow libtensorflow_framework
	${INSTALL_PROGRAM} ${WRKDIR}/lib_package/lib/${l}.so.${SOVERSION} \
	  ${STAGEDIR}${PREFIX}/lib/
	${RLN} ${STAGEDIR}${PREFIX}/lib/${l}.so.${SOVERSION} \
	  ${STAGEDIR}${PREFIX}/lib/${l}.so.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/${l}.so.1 \
	  ${STAGEDIR}${PREFIX}/lib/${l}.so
.endfor

.include <bsd.port.mk>
