PORTNAME=	tensorflow
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ba7501696cc.patch:-p1 667cf3ed2d7.patch:-p1

MAINTAINER=	amzo1337@gmail.com
COMMENT=	Computation using data flow graphs for scalable machine learning
WWW=		https://www.tensorflow.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.22.0:devel/py-grpcio-tools@${PY_FLAVOR} \
		bash:shells/bash \
		bazel:devel/bazel5 \
		cython:lang/cython \
		git:devel/git \
		patchelf:sysutils/patchelf \
		swig:devel/swig
LIB_DEPENDS=	libnsync.so:devel/nsync \
		libgpr.so:devel/grpc \
		libpng.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libabsl_base.so:devel/abseil \
		libsqlite3.so:databases/sqlite3 \
		libicuio.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libprotobuf.so:devel/protobuf \
		libgif.so:graphics/giflib \
		libcurl.so:ftp/curl \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	pybind11>=2.6.2:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}absl-py>=1.0.0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astunparse>=1.6.0:devel/py-astunparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flatbuffers>=23.1.21:devel/py-flatbuffers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gast>=0.2.1:devel/py-gast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-pasta>=0.1.1:devel/py-google-pasta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.9.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=2.3.2:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.20.3:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.6:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.11.0:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.24.3:devel/py-grpcio@${PY_FLAVOR}

USES=		jpeg perl5 python shebangfix ssl
USE_CXXSTD=	c++17
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_PYTHON=	distutils

SHEBANG_GLOB=	*.py

BINARY_ALIAS=	python3=${PYTHON_CMD}

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

	@${CP} ${PATCHDIR}/bazelrc ${WRKDIR}/bazelrc
	@${CP} -R ${PATCHDIR}/bazel/* \
		${WRKSRC}/third_party/

	@${REINPLACE_CMD} "s#%%BAZEL_DIR%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIST%%#${WRKDIR}#" ${WRKDIR}/bazelrc

	# copy the toolchain over
	@${CP} -R ${PATCHDIR}/freebsd \
		${WRKSRC}/

	@${REINPLACE_CMD} "s#%%PATH%%#${PATH}#" ${WRKDIR}/bazelrc

	@${REINPLACE_CMD} -e "s#%%LOCALBASE%%#${LOCALBASE}#" \
		${WRKDIR}/bazelrc \
		${WRKSRC}/freebsd/cc_toolchain_config.bzl \
		${WRKSRC}/.bazelrc

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
				gif hwloc icu jsoncpp_git libjpeg_turbo nasm nsync opt_einsum_archive org_sqlite pasta png pybind11 six_archive snappy \
				tblib_archive termcolor_archive typing_extensions_archive wrapt zlib" \
		./configure

do-build:
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} build --jobs ${TF_JOBS_NUMBER} ${BAZEL_COPT} --host_copt="-I${LOCALBASE}/include" \
		--host_linkopt="-L${LOCALBASE}/lib -lexecinfo" ${BAZEL_LINKOPT} --copt="-I${LOCALBASE}/include" \
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

post-install: # autoplist: thousands of files, all under ${PYTHON_SITELIBDIR}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|^${LOCALBASE}/||} -type f -or -type l | ${GREP} -v "egg-info/" >> ${TMPPLIST}

.include <bsd.port.mk>
