PORTNAME=	tensorflow
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.1
PORTREVISION=	14
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	amzo1337@gmail.com
COMMENT=	Computation using data flow graphs for scalable machine learning
WWW=		https://www.tensorflow.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.22.0:devel/py-grpcio-tools@${PY_FLAVOR} \
		bash:shells/bash \
		cython:lang/cython \
		swig:devel/swig \
		bazel:devel/bazel5 \
		git:devel/git
LIB_DEPENDS=	libnsync.so:devel/nsync \
		libgpr.so:devel/grpc \
		libpng.so:graphics/png \
		libsnappy.so:archivers/snappy \
		liblmdb.so:databases/lmdb \
		libsqlite3.so:databases/sqlite3 \
		libicuio.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libpcre.so:devel/pcre \
		libnsync.so:devel/nsync \
		libprotobuf.so:devel/protobuf \
		libprotobuf-c.so:devel/protobuf-c \
		libre2.so:devel/re2 \
		libgif.so:graphics/giflib \
		libcurl.so:ftp/curl \
		libflatbuffers.so:devel/flatbuffers \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	pybind11>=2.6.2:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}absl-py>=1.0.0:devel/py-absl-py \
		${PYTHON_PKGNAMEPREFIX}astunparse>=1.6.3:devel/py-astunparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.9.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flatbuffers>=2.0:devel/py-flatbuffers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gast>=0.5.3:devel/py-gast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-pasta>=0.1.7:devel/py-google-pasta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.22.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras-preprocessing>=1.1.1:math/py-keras-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.14.1:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=3.3.0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		pybind11>=2.6.2:devel/pybind11

USES=		jpeg llvm:16 python shebangfix ssl
USE_CXXSTD=     c++17
USE_GITHUB=	yes
USE_PYTHON=	distutils

SHEBANG_GLOB=	*.py

BAZEL_BOOT=	--output_user_root=${WRKDIR}/bazel_out

PLIST_SUB=	TF_PORT_VERSION=${PORTVERSION}

OPTIONS_DEFINE=			CPU_OPTS XLA
OPTIONS_RADIO=			PARALLEL_JOBS
OPTIONS_RADIO_PARALLEL_JOBS=	JOBS_1 JOBS_HALF JOBS_ALL
PARALLEL_JOBS_DESC=		How many jobs to run during build?
OPTIONS_DEFAULT=		JOBS_HALF

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

post-patch:
	# Set up a local repository with our pre-downloaded packages
	# This prevents bazel downloading the files without modifying
	# the bzl files.
	@${MKDIR} ${WRKDIR}/bazel-cache
	@${MKDIR} ${WRKDIR}/bazel-dist
	@${MKDIR} ${WRKDIR}/.bin

.for file in ${DISTFILES:C/\:(.*)//}
	@${ECHO} "Moving ${file} to ${WRKDIR}/bazel-dist"
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKDIR}/bazel-dist
.endfor

	@${CP} ${PATCHDIR}/bazelrc ${WRKDIR}/bazelrc
	@${CP} -R ${PATCHDIR}/bazel/* \
		${WRKSRC}/third_party/

	@${LN} -s ${PYTHON_CMD} ${WRKDIR}/.bin/python3
	
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} "s#--batch#${BAZEL_BOOT}\', \'--batch#" \
		configure.py

	${REINPLACE_CMD} "s#%%PYTHON%%#${PYTHON_VERSION}#" ${WRKSRC}/configure \
		${WRKSRC}/third_party/freebsd_python_fix.patch \
		${WRKSRC}/tensorflow/compiler/mlir/quantization/tensorflow/BUILD

	@${REINPLACE_CMD} "s#%%BAZEL_DIR%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIST%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%MLIR_LLVM_PATCH%%#/${WRKSRC}/bazel/bazel_llvm-raw_utils_bazel_configure.bzl#" \
		${WRKSRC}/tensorflow/compiler/mlir/hlo/WORKSPACE

	# use system pybind11, but use sed to fix includes, too many to maintain with patches
	@${FIND} ${WRKSRC} -type f -name '*.cc' | ${XARGS} ${REINPLACE_CMD} "s#include\/pybind11#pybind11#"


	# copy the toolchain over
	@${CP} -R ${PATCHDIR}/freebsd \
		${WRKSRC}/

	@${REINPLACE_CMD} "s#%%PATH%%#${PATH}#" ${WRKDIR}/bazelrc

	@${REINPLACE_CMD} "s#%%PYTHON%%#${PYTHON_CMD}#" ${WRKSRC}/.bazelrc

	@${REINPLACE_CMD} \
		-e "s#%%LOCALBASE%%#${LOCALBASE}#" \
		-e "s#%%LLVM_PREFIX%%#${LLVM_PREFIX}#g" \
		-e "s#%%LLVM_VERSION%%#${LLVM_VERSION}#g" \
		${WRKDIR}/bazelrc \
		${WRKSRC}/third_party/absl/system.absl.strings.BUILD \
		${WRKSRC}/freebsd/cc_toolchain_config.bzl \
		${WRKSRC}/.bazelrc \
		${WRKSRC}/tensorflow/tools/proto_text/BUILD \
		${WRKSRC}/tensorflow/BUILD \
		${WRKSRC}/tensorflow/core/BUILD \
		${WRKSRC}/third_party/systemlibs/protobuf.BUILD


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
		TF_SYSTEM_LIBS="absl_py astor_archive astunparse_archive boringssl com_github_googlecloudplatform_google_cloud_cpp com_github_grpc_grpc \
				com_google_absl com_google_protobuf curl cython dill_archive double_conversion functools32_archive gast_archive \
				gif hwloc icu jsoncpp_git libjpeg_turbo lmdb nasm nsync opt_einsum_archive org_sqlite pasta png pybind11 six_archive snappy \
				tblib_archive termcolor_archive typing_extensions_archive wrapt zlib" \
		./configure

do-build:
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} build --jobs ${TF_JOBS_NUMBER} ${BAZEL_COPT} --host_copt="-I${LOCALBASE}/include" \
		--host_linkopt="-L${LOCALBASE}/lib -lexecinfo" --linkopt="-L${LOCALBASE}/lib -lexecinfo" --copt="-I${LOCALBASE}/include" \
		--verbose_failures -s \
		--distdir=${WRKDIR}/bazel-dist \
		//tensorflow:libtensorflow_framework.so \
		//tensorflow:libtensorflow.so \
		//tensorflow:libtensorflow_cc.so \
		//tensorflow:install_headers \
		//tensorflow/tools/pip_package:build_pip_package


	@cd ${WRKSRC} && ${SETENV} TMPDIR=${WRKDIR} \
		bazel-bin/tensorflow/tools/pip_package/build_pip_package \
		${WRKDIR}/whl

do-install:
	@${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}/${LOCALBASE}/include/tensorflow

	@${UNZIP_NATIVE_CMD} -d ${STAGEDIR}/${PYTHON_SITELIBDIR} ${WRKDIR}/whl/${PORTNAME}-${PORTVERSION}-*.whl

	# put headers in the right folder
	${CP} -R ${WRKSRC}/bazel-bin/tensorflow/include/tensorflow \
		${STAGEDIR}/${LOCALBASE}/include/

	# pc files and libraries
	${INSTALL_DATA} ${PATCHDIR}/tensorflow.pc ${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/
	${INSTALL_DATA} ${PATCHDIR}/tensorflow_cc.pc ${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/

	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" \
		${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/tensorflow.pc \
		${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/tensorflow_cc.pc

	@${REINPLACE_CMD} "s#%%VERSION%%#${PORTVERSION}#" \
		${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/tensorflow.pc	

	#cleanup
	${RM} ${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/*.bak

	# install the libraries and strip
	@${FIND} ${WRKSRC}/bazel-bin/tensorflow/ -depth 1 -name "*.so*" | ${XARGS} -I{} \
		${INSTALL_LIB} {} ${STAGEDIR}/${LOCALBASE}/lib/

	@${FIND} ${STAGEDIR}/${LOCALBASE}/lib -name "*.so*" | ${XARGS} ${STRIP_CMD}

post-install: # autoplist: thousands of files, all under ${PYTHON_SITELIBDIR}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|^${LOCALBASE}/||} -type f -or -type l | grep -v "egg-info/" >> ${TMPPLIST}

.include <bsd.port.mk>
