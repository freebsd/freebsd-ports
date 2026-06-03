PORTNAME=	tensorflow
DISTVERSIONPREFIX=	v
DISTVERSION=	2.21.0
PORTREVISION=	3
CATEGORIES=	science python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computation using data flow graphs for scalable machine learning
WWW=		https://www.tensorflow.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.22.0:devel/py-grpcio-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		bash:shells/bash \
		bazel:devel/bazel7 \
		cython:lang/cython \
		git:devel/git \
		patchelf:sysutils/patchelf \
		pybind11>=2.6.2:devel/pybind11 \
		swig:devel/swig \
		xxd:sysutils/xxd
LIB_DEPENDS=	libpng.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libabsl_base.so:devel/abseil \
		libsqlite3.so:databases/sqlite3 \
		libicuio.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libprotobuf.so:devel/protobuf \
		libgif.so:graphics/giflib \
		libcurl.so:ftp/curl \
		libre2.so:devel/re2 \
		libhwloc.so:devel/hwloc2
RUN_DEPENDS=	pybind11>=2.6.2:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}absl-py>=2.0.0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astunparse>=1.6.0:devel/py-astunparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flatbuffers>=25.9.23:devel/py-flatbuffers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gast>=0.2.1:devel/py-gast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-pasta>=0.1.1:devel/py-google-pasta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.9.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.20.3:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.6:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.11.0:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.24.3:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ml-dtypes>=0.3.1:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=3.3.0:math/py-opt-einsum@${PY_FLAVOR}

USES=		java jpeg perl5 python shebangfix ssl
JAVA_VERSION=	21
JAVA_VENDOR=	openjdk
USE_CXXSTD=	c++17
USE_GITHUB=	yes
USE_PERL5=	build
USE_PYTHON=	distutils

SHEBANG_GLOB=	*.py

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=			CPU_OPTS XLA
OPTIONS_RADIO=			PARALLEL_JOBS
OPTIONS_RADIO_PARALLEL_JOBS=	JOBS_1 JOBS_HALF JOBS_ALL
PARALLEL_JOBS_DESC=		How many jobs to run during build?
OPTIONS_DEFAULT=		JOBS_ALL

JOBS_1_DESC=			Run one job
JOBS_1_VARS=			TF_JOBS_NUMBER=1
JOBS_HALF_DESC=			Run half jobs
JOBS_HALF_VARS=			TF_JOBS_NUMBER="`expr \( ${MAKE_JOBS_NUMBER} + 1 \) / 2`"
JOBS_ALL_DESC=			Run all jobs
JOBS_ALL_VARS=			TF_JOBS_NUMBER=${MAKE_JOBS_NUMBER}

CPU_OPTS_DESC=			Enable optimisations using features available on your CPU
CPU_OPTS_VARS=			CPU_TARGET=native BAZEL_COPT="-c opt --copt=-march=native --copt=-mfpmath=sse"
CPU_OPTS_VARS_OFF=		CPU_TARGET=x86-64

XLA_DESC=			Accelerated Linear Algebra
XLA_VARS=			XLA_OPT="1"
XLA_VARS_OFF=			XLA_OPT="0"

.include "Makefile.MASTER_SITES"

BAZEL_BOOT=	--output_user_root=${WRKDIR}/bazel_out
.if !defined(WITH_DEBUG)
# For the reason why the linker is used for the strip, see PR 280234.
BAZEL_LINKOPT=	--linkopt=-Wl,--strip-all
.endif

post-patch:
	# Set up a local repository with our pre-downloaded packages
	# This prevents bazel downloading the files without modifying
	# the bzl files.
	@${MKDIR} ${WRKDIR}/bazel-dist

.for file in ${DISTFILES:C/\:(.*)//}
	@${ECHO} "Moving ${file} to ${WRKDIR}/bazel-dist"
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKDIR}/bazel-dist
.endfor

	# Pre-populate repository cache for files fetched via ctx.download()
	# (these are not served by --distdir; must be in --repository_cache)
	@${MKDIR} ${WRKDIR}/bazel-cache/content_addressable/sha256/12cffc7274190ca1693a52ccd8303e719407e707c8557ddfb7eef81f208efaab
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/libtinfo.so.5 \
		${WRKDIR}/bazel-cache/content_addressable/sha256/12cffc7274190ca1693a52ccd8303e719407e707c8557ddfb7eef81f208efaab/file
	@${MKDIR} ${WRKDIR}/bazel-cache/content_addressable/sha256/5e8ee902c8906ddb7779fd36dc9979cb08b51fbebf7c0b1a9aeb78af382af590
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/copyright.txt \
		${WRKDIR}/bazel-cache/content_addressable/sha256/5e8ee902c8906ddb7779fd36dc9979cb08b51fbebf7c0b1a9aeb78af382af590/file

	@${CP} ${PATCHDIR}/bazelrc ${WRKDIR}/bazelrc
	@${CP} -R ${PATCHDIR}/bazel/* \
		${WRKSRC}/third_party/
	@${CP} ${PATCHDIR}/bazel/rules_python_freebsd.patch \
		${WRKSRC}/third_party/xla/third_party/py/
	@${CP} ${PATCHDIR}/bazel/fix-environ.patch \
		${WRKSRC}/third_party/xla/third_party/
	@${CP} ${PATCHDIR}/llvm_freebsd.patch \
		${WRKSRC}/third_party/xla/third_party/llvm/freebsd.patch
	@${CP} ${PATCHDIR}/grpc.bazel.BUILD \
		${WRKSRC}/third_party/systemlibs/grpc.bazel.BUILD
	@${CP} ${PATCHDIR}/grpc.bazel.python_rules.bzl \
		${WRKSRC}/third_party/systemlibs/grpc.bazel.python_rules.bzl
	@${CP} ${PATCHDIR}/grpc.bazel.cc_grpc_library.bzl \
		${WRKSRC}/third_party/systemlibs/grpc.bazel.cc_grpc_library.bzl

	@${REINPLACE_CMD} "s#%%BAZEL_DIR%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIST%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%WRKSRC%%#${WRKSRC}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%JAVA_HOME%%#${JAVA_HOME}#" ${WRKDIR}/bazelrc

	# copy the toolchain over
	@${CP} -R ${PATCHDIR}/freebsd \
		${WRKSRC}/

	@${REINPLACE_CMD} "s#%%PATH%%#${PATH}#" ${WRKDIR}/bazelrc

	@${REINPLACE_CMD} -e "s#%%LOCALBASE%%#${LOCALBASE}#" \
		${WRKDIR}/bazelrc \
		${WRKSRC}/freebsd/cc_toolchain_config.bzl \
		${WRKSRC}/.bazelrc \
		${WRKSRC}/WORKSPACE
	@${REINPLACE_CMD} -e "s#%%NUMPY_INCLUDEDIR%%#${PYTHON_SITELIBDIR}/numpy/_core/include#g" \
		${WRKDIR}/bazelrc \
		${WRKSRC}/freebsd/cc_toolchain_config.bzl

	@${REINPLACE_CMD} -e "s#%%PYTHON_VER%%#${PYTHON_VER}#g" \
		${WRKSRC}/WORKSPACE

	# Fix Python runtime headers: replace rules_python CC toolchain alias with
	# a direct cc_library using a symlink to the system Python headers.
	@${REINPLACE_CMD} \
		"s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		${WRKDIR}/bazelrc
	@${CP} ${PATCHDIR}/pthreadpool-freebsd-alloca.patch \
		${WRKSRC}/third_party/xla/third_party/pthreadpool/freebsd_alloca.patch
	@${CP} ${PATCHDIR}/xnnpack-freebsd-mmap.patch \
		${WRKSRC}/third_party/xla/third_party/xnnpack/freebsd_mmap.patch
	@${CP} ${PATCHDIR}/protobuf-freebsd-upb.patch \
		${WRKSRC}/third_party/xla/third_party/protobuf/freebsd_upb.patch
	@${CP} ${PATCHDIR}/cpuinfo-freebsd-alwayslink.patch \
		${WRKSRC}/third_party/cpuinfo/cpuinfo_freebsd_alwayslink.patch
	@${CP} ${PATCHDIR}/grpc-no-go-sdk.patch \
		${WRKSRC}/third_party/xla/third_party/grpc/grpc_no_go.patch

	@${LN} -sf ${PYTHON_INCLUDEDIR} \
		${WRKSRC}/third_party/xla/third_party/python_runtime/python_include

	# Create pypi hub stub (FreeBSD has no platform wheels in requirements_lock)
	@${MKDIR} ${WRKSRC}/bazel_pypi_hub
	@${PRINTF} 'package(default_visibility = ["//visibility:public"])\nexports_files(["requirements.bzl"])\n' \
		> ${WRKSRC}/bazel_pypi_hub/BUILD.bazel
	@${PRINTF} 'def install_deps(**kwargs):\n    pass\n' \
		> ${WRKSRC}/bazel_pypi_hub/requirements.bzl
	@${TOUCH} ${WRKSRC}/bazel_pypi_hub/WORKSPACE
.for _pypi_pkg in absl_py astor astunparse auditwheel dill flatbuffers gast h5py jax \
    keras lit ml_dtypes opt_einsum packaging portpicker protobuf requests \
    scipy setuptools tblib termcolor typing_extensions wheel wrapt zstandard
	@${MKDIR} ${WRKSRC}/bazel_pypi_hub/${_pypi_pkg}
	@${PRINTF} 'package(default_visibility = ["//visibility:public"])\npy_library(name = "pkg", srcs = [])\npy_library(name = "lib", srcs = [])\npy_library(name = "whl", srcs = [])\nalias(name = "${_pypi_pkg}", actual = ":pkg")\n' \
		> ${WRKSRC}/bazel_pypi_hub/${_pypi_pkg}/BUILD.bazel
	@${TOUCH} ${WRKSRC}/bazel_pypi_hub/${_pypi_pkg}/WORKSPACE
.endfor
	# numpy needs extra cc_library for numpy_headers used by C++ deps
	@${MKDIR} ${WRKSRC}/bazel_pypi_hub/numpy
	@${MKDIR} ${WRKSRC}/bazel_pypi_hub/numpy/include
	@${LN} -sf ${PYTHON_SITELIBDIR}/numpy/_core/include/numpy \
		${WRKSRC}/bazel_pypi_hub/numpy/include/numpy
	# build_pip_package.py expects site-packages/numpy/{_core,core}/include
	@${MKDIR} ${WRKSRC}/bazel_pypi_hub/numpy/site-packages/numpy/core
	@${LN} -sf ${PYTHON_SITELIBDIR}/numpy/_core/include \
		${WRKSRC}/bazel_pypi_hub/numpy/site-packages/numpy/core/include
	@${PRINTF} 'package(default_visibility = ["//visibility:public"])\npy_library(name = "pkg", srcs = [])\npy_library(name = "lib", srcs = [])\nalias(name = "numpy", actual = ":pkg")\ncc_library(\n    name = "numpy_headers",\n    hdrs = glob(["include/**/*.h"]),\n    includes = ["include"],\n)\n' \
		> ${WRKSRC}/bazel_pypi_hub/numpy/BUILD.bazel
	@${TOUCH} ${WRKSRC}/bazel_pypi_hub/numpy/WORKSPACE

do-configure:
	@cd ${WRKSRC} && ${SETENV} \
		PYTHON_BIN_PATH=${PYTHON_CMD} \
		PYTHON_LIB_PATH="${PYTHON_SITELIBDIR}" \
		KERAS_HOME="${WRKDIR}/.keras" \
		TF_NEED_OPENCL_SYCL=0 \
		TF_ENABLE_XLA=${XLA_OPT} \
		TF_NEED_OPENCL=0 \
		TF_NEED_MPI=0 \
		TF_NEED_TENSORRT=0 \
		TF_NEED_NGRAPH=0 \
		TF_NEED_IGNITE=0 \
		TF_NEED_ROCM=0 \
		TF_NEED_CUDA=0 \
		TF_SET_ANDROID_WORKSPACE=0 \
		TF_DOWNLOAD_CLANG=0 \
		TF_NEED_NCCL=0 \
		TF_IGNORE_MAX_BAZEL_VERSION=1 \
		CC_OPT_FLAGS="-march=${CPU_TARGET} -I${LOCALBASE}/include" \
		PREFIX="${LOCALBASE}" \
		TF_SYSTEM_LIBS="astor_archive astunparse_archive boringssl com_github_googlecloudplatform_google_cloud_cpp \
				com_googlesource_code_re2 curl cython dill_archive functools32_archive gast_archive \
				gif hwloc icu jsoncpp_git libjpeg_turbo nasm org_sqlite pasta png pybind11 six_archive snappy \
				tblib_archive termcolor_archive typing_extensions_archive wrapt zlib" \
		./configure
	@${REINPLACE_CMD} 's/,com_google_absl//g;s/,absl_py//g;s/absl_py,//g' ${WRKSRC}/.tf_configure.bazelrc

post-configure:
	# BINARY_ALIAS creates a relative symlink for python3 that breaks inside
	# the poudriere jail (relative path resolves under /wrkdirs/usr/local/…
	# instead of /usr/local/…).  Replace it with an absolute symlink.
	@${RM} ${WRKDIR}/.bin/python3
	@${LN} -s ${PYTHON_CMD} ${WRKDIR}/.bin/python3

do-build:
	# Fetch rules_java to ensure it is extracted from the Bazel install, then inject
	# compatibility stubs for rules_java 7.x + protobuf 6.31.1 (which needs 8.x APIs).
	# Both @rules_java (WORKSPACE) and @@rules_java (Bzlmod canonical = rules_java_builtin)
	# must have the stubs; protobuf 6.31.1 uses the Bzlmod canonical form.
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} fetch @rules_java//:BUILD
	@BAZEL_OB=$$(cd ${WRKSRC} && bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} info output_base 2>/dev/null); \
	for RJNAME in rules_java rules_java_builtin; do \
		RJDIR="$${BAZEL_OB}/external/$${RJNAME}"; \
		if [ -d "$${RJDIR}/java/private" ]; then \
			${CP} ${FILESDIR}/rules_java.java.private.proto_support.bzl \
				$${RJDIR}/java/private/proto_support.bzl; \
			${CP} ${FILESDIR}/rules_java.java.common.proguard_spec_info.bzl \
				$${RJDIR}/java/common/proguard_spec_info.bzl 2>/dev/null || true; \
		else \
			${ECHO_MSG} "WARNING: rules_java external dir $${RJNAME} not found; build may fail"; \
		fi; \
	done
	# Fetch llvm-project and fix config.bzl: replace Linux-only CPU-based FreeBSD
	# condition with platform-based @platforms//os:freebsd so exec/tool builds also
	# use posix_defines (no HAVE_GETAUXVAL / HAVE_MALLINFO) and the correct triple.
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} fetch @@llvm-project//llvm:Support
	@LLVM_OB=$$(cd ${WRKSRC} && bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} info output_base 2>/dev/null); \
		LLVMCONF="$${LLVM_OB}/external/llvm-raw/utils/bazel/llvm-project-overlay/llvm/config.bzl"; \
		if [ -f "$${LLVMCONF}" ]; then \
			${PYTHON_CMD} ${PATCHDIR}/fix-llvm-config.py "$${LLVMCONF}"; \
		else \
			${ECHO_MSG} "WARNING: llvm config.bzl not found at $${LLVMCONF}; build may fail"; \
		fi
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} build --jobs ${TF_JOBS_NUMBER} ${BAZEL_COPT} --host_copt="-I${LOCALBASE}/include" \
		--host_linkopt="-L${LOCALBASE}/lib -lexecinfo" ${BAZEL_LINKOPT} --copt="-I${LOCALBASE}/include" \
		--verbose_failures -s \
		--distdir=${WRKDIR}/bazel-dist \
		//tensorflow/tools/pip_package:wheel

	@${MKDIR} ${WRKDIR}/whl
	@${CP} ${WRKSRC}/bazel-bin/tensorflow/tools/pip_package/wheel_house/*.whl \
		${WRKDIR}/whl/

do-install:
	@${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}

	@${UNZIP_NATIVE_CMD} -d ${STAGEDIR}/${PYTHON_SITELIBDIR} ${WRKDIR}/whl/${PORTNAME}-${PORTVERSION}-*.whl

post-install: # autoplist: thousands of files, all under ${PYTHON_SITELIBDIR}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|^${LOCALBASE}/||} -type f -or -type l | ${GREP} -v "egg-info/" >> ${TMPPLIST}

do-test:
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} test \
		--jobs ${TF_JOBS_NUMBER} ${BAZEL_COPT} --host_copt="-I${LOCALBASE}/include" \
		--host_linkopt="-L${LOCALBASE}/lib -lexecinfo" ${BAZEL_LINKOPT} --copt="-I${LOCALBASE}/include" \
		--verbose_failures \
		--distdir=${WRKDIR}/bazel-dist \
		--test_output=errors \
		--keep_going \
		//tensorflow/python/autograph/...

test-quick: build
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example-quick-training.py

# tests as of 2.21.0: Executed 76 out of 76 tests: 76 tests pass.

.include <bsd.port.mk>
