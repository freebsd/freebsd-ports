# $FreeBSD$

PORTNAME=	tensorflow
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0
PORTREVISION=	6
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	amzo1337@gmail.com
COMMENT=	Computation using data flow graphs for scalable machine learning

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.22.0:devel/py-grpcio-tools@${PY_FLAVOR} \
		bash:shells/bash \
		cython:lang/cython \
		swig3.0:devel/swig30 \
		bazel:devel/bazel029
LIB_DEPENDS=	libsnappy.so:archivers/snappy \
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
		libpng.so:graphics/png \
		libgpr.so:devel/grpc \
		libcurl.so:ftp/curl \
		libgoogle_cloud_cpp_common.so:devel/google-cloud-cpp \
		libflatbuffers.so:devel/flatbuffers \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl>=0.7.1:devel/py-absl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astor>=0.5:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gast>=0.2.2:devel/py-gast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.11.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-pasta>=0.1.7:devel/py-google-pasta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.22.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras>=2.2.4:math/py-keras@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.11.2:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.6+ shebangfix jpeg ssl
SHEBANG_GLOB=	*.py
USE_GITHUB=	yes
USE_PYTHON=	distutils

BAZEL_BOOT=	--output_user_root=${WRKDIR}/bazel_out

PLIST_SUB=	TF_PORT_VERSION=${PORTVERSION}

OPTIONS_DEFINE=		CPU_OPTS

CPU_OPTS_DESC=		Enable optimisations using features available on your CPU
CPU_OPTS_VARS=		CPU_TARGET=native BAZEL_COPT="-c opt --copt=-march=native --copt=-mfpmath=sse"
CPU_OPTS_VARS_OFF=	CPU_TARGET=x86-64

.include "Makefile.MASTER_SITES"

post-patch:
	# Set up a local repository with our pre-downloaded packages
	# This prevents bazel downloading the files without modifying
	# the bzl files.
	@${MKDIR} ${WRKDIR}/bazel-cache
	@${MKDIR} ${WRKDIR}/bazel-distdir

.for file in ${DISTFILES:C/\:(.*)//}
	@${ECHO} "Moving ${file} to ${WRKDIR}/bazel-cache"
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKDIR}/bazel-distdir
.endfor

	@cd ${WRKSRC} && \
		${REINPLACE_CMD} "s#--batch#${BAZEL_BOOT}\', \'--batch#" \
		configure.py

	@${CP} ${PATCHDIR}/bazelrc ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIR%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIST%%#${WRKDIR}#" ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKDIR}/bazelrc \
		${WRKSRC}/tensorflow/tensorflow.bzl ${WRKSRC}/.bazelrc \
		${WRKSRC}/tensorflow/core/BUILD \
		${WRKSRC}/third_party/systemlibs/protobuf.bzl

do-configure:
	@cd ${WRKSRC} && ${SETENV} \
		PYTHON_BIN_PATH=${PYTHON_CMD} \
		PYTHON_LIB_PATH="${PYTHON_SITELIBDIR}" \
		TF_NEED_JEMALLOC=0 \
		TF_NEED_KAFKA=0 \
		TF_NEED_OPENCL_SYCL=0 \
		TF_NEED_AWS=0 \
		TF_NEED_GCP=0 \
		TF_NEED_HDFS=0 \
		TF_NEED_S3=0 \
		TF_ENABLE_XLA=0 \
		TF_NEED_GDR=0 \
		TF_NEED_VERBS=0 \
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
		TF_NEED_OPENCL=0 \
		TF_IGNORE_MAX_BAZEL_VERSION=1 \
		CC_OPT_FLAGS="-march=${CPU_TARGET} -I${LOCALBASE}/include" \
		PREFIX="${LOCALBASE}" \
		TF_SYSTEM_LIBS="absl_py astor_archive boringssl com_github_googleapis_googleapis com_github_googlecloudplatform_google_cloud_cpp com_google_protobuf \
				com_google_protobuf_cc com_googlesource_code_re2 curl cython double_conversion enum34_archive flatbuffers gast_archive gif_archive \
				grpc hwloc icu jpeg jsoncpp_git keras_applications_archive lmdb nasm nsync org_sqlite pasta pcre png_archive protobuf_archive \
				six_archive snappy swig termcolor_archive wrapt zlib_archive" \
		./configure

do-build:
	@cd ${WRKSRC} && \
		bazel --bazelrc="${WRKDIR}/bazelrc" ${BAZEL_BOOT} build ${BAZEL_COPT} --host_copt="-I${LOCALBASE}/include" \
		--host_linkopt="-L${LOCALBASE}/lib" --linkopt="-L${LOCALBASE}/lib" --config=opt \
		--incompatible_no_support_tools_in_action_inputs=false \
		--verbose_failures -s \
		//tensorflow:libtensorflow.so \
		//tensorflow:libtensorflow_cc.so \
		//tensorflow:install_headers \
		//tensorflow/tools/pip_package:build_pip_package
	@cd ${WRKSRC} && ${SETENV} TMPDIR=${WRKDIR} \
		bazel-bin/tensorflow/tools/pip_package/build_pip_package \
		${WRKDIR}/whl

do-install:
	@${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}
	@${MKDIR} ${WRKDIR}/tmp
	@${UNZIP_NATIVE_CMD} -d ${WRKDIR}/tmp ${WRKDIR}/whl/${PORTNAME}-${PORTVERSION}-*.whl
	@${FIND} ${WRKDIR}/tmp -name "*.so*" | ${XARGS} ${STRIP_CMD}
	cd ${WRKDIR}/tmp && ${COPYTREE_SHARE} ${PORTNAME}-${PORTVERSION}.dist-info \
		${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR}/tmp/${PORTNAME}-${PORTVERSION}.data/purelib && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}

post-install: # autoplist: thousands of files, all under ${PYTHON_SITELIBDIR}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|^${LOCALBASE}/||} -type f -or -type l | grep -v "egg-info/" >> ${TMPPLIST}

.include <bsd.port.mk>
