PORTNAME=	jaxlib
DISTVERSIONPREFIX=	jax-v
DISTVERSION=	0.12.0.1
PORTREVISION=	1
CATEGORIES=	math python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Support library for JAX
WWW=		https://docs.jax.dev/en/latest/ \
		https://github.com/jax-ml/jax

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		bash:shells/bash \
		bazel:devel/bazel8
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ml-dtypes>=0.5.0:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.15:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>0:math/py-jax@${PY_FLAVOR}

USES=		java:build python shebangfix
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	jax-ml
GH_PROJECT=	jax

JAVA_VERSION=	21
JAVA_VENDOR=	openjdk

BINARY_ALIAS=	python3=${PYTHON_CMD}

# Bazel dependencies that are fetched ahead of time, see Makefile.MASTER_SITES
XLA_COMMIT=	d867969800d4a8fd045505eabc65e1e66f30794f
RMT_COMMIT=	3a4df0c8e9e51687ac4c62c793a00a27286e5e83
BCR_COMMIT=	4b013400f925668c1cc8b8ca6e3b8e8792fd8b98
RULES_CC_VERSION=	0.2.25

.include "Makefile.MASTER_SITES"

.include <bsd.port.pre.mk>

XLA_DIR=	${WRKDIR}/xla-${XLA_COMMIT}
RMT_DIR=	${WRKDIR}/rules_ml_toolchain-${RMT_COMMIT}
BCR_DIR=	${WRKDIR}/bazel-central-registry-${BCR_COMMIT}
PYPI_STUB=	${WRKDIR}/pypi_stub

BAZEL_ARGS=	--bazelrc=${WRKDIR}/bazelrc --output_user_root=${WRKDIR}/bazel_out

post-extract:
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${XLA_COMMIT}.tar.gz -C ${WRKDIR}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${RMT_COMMIT}.tar.gz -C ${WRKDIR}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${BCR_COMMIT}.tar.gz -C ${WRKDIR}
.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/rules_cc-${RULES_CC_VERSION}.tar.gz -C ${WRKDIR}
.endif

post-patch:
	# Patch the modules that are overridden by the build
	@${PATCH} -s -p1 -d ${XLA_DIR} -i ${FILESDIR}/xla.patch
	@${PATCH} -s -p1 -d ${RMT_DIR} -i ${FILESDIR}/rmt.patch
	@${CP} ${FILESDIR}/protobuf-freebsd-upb.patch \
		${WRKSRC}/third_party/protobuf/freebsd_upb.patch
	@${CP} ${FILESDIR}/curl-freebsd.patch \
		${WRKSRC}/third_party/protobuf/curl_freebsd.patch
	@${REINPLACE_CMD} -e 's|%%PYPI_STUB%%|${PYPI_STUB}|' \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/MODULE.bazel ${XLA_DIR}/MODULE.bazel ${RMT_DIR}/MODULE.bazel

	# Bazel reads the pre-downloaded distfiles from the repository cache
	# where they are keyed by checksum, and the ones fetched by module
	# extensions with a canonical id also need a marker with the id.
	@${MKDIR} ${WRKDIR}/bazel-cache/content_addressable/sha256
.for file in ${DISTFILES:C/\:(.*)//}
	@h=$$(sha256 -q ${DISTDIR}/${DIST_SUBDIR}/${file}) && \
		${MKDIR} ${WRKDIR}/bazel-cache/content_addressable/sha256/$${h} && \
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} \
			${WRKDIR}/bazel-cache/content_addressable/sha256/$${h}/file
.endfor
	@while read h i; do \
		${TOUCH} ${WRKDIR}/bazel-cache/content_addressable/sha256/$${h}/id-$${i}; \
	done < ${FILESDIR}/repository-cache-ids

	@${CP} ${FILESDIR}/bazelrc ${WRKDIR}/bazelrc
	@${REINPLACE_CMD} -e 's|%%BCR_DIR%%|${BCR_DIR}|g' \
		-e 's|%%XLA_DIR%%|${XLA_DIR}|g' \
		-e 's|%%RMT_DIR%%|${RMT_DIR}|g' \
		-e 's|%%WRKDIR%%|${WRKDIR}|g' \
		-e 's|%%PYTHON_VER%%|${PYTHON_VER}|g' \
		-e 's|%%JAVA_HOME%%|${JAVA_HOME}|g' \
		-e 's|%%JOBS%%|${MAKE_JOBS_NUMBER}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKDIR}/bazelrc

.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
	# rules_cc runs /usr/bin/clang unconditionally, so it is replaced
	# with a wrapper to make WITH_CCACHE_BUILD work
	@${PRINTF} '#!/bin/sh\nexport CCACHE_DIR=${CCACHE_DIR} CCACHE_NOHASHDIR=1 CCACHE_SLOPPINESS=include_file_mtime,time_macros,file_macro\nexec ${CCACHE_BIN} /usr/bin/clang "$$@"\n' \
		> ${WRKDIR}/ccache-clang
	@${CHMOD} +x ${WRKDIR}/ccache-clang
	@${PATCH} -s -p1 -d ${WRKDIR}/rules_cc-${RULES_CC_VERSION} -i ${FILESDIR}/rules_cc-ccache.patch
	@${REINPLACE_CMD} -e 's|%%CCACHE_CLANG%%|${WRKDIR}/ccache-clang|' \
		${WRKDIR}/rules_cc-${RULES_CC_VERSION}/cc/private/toolchain/bsd_cc_toolchain_config.bzl
	@${ECHO} "common --override_module=rules_cc=${WRKDIR}/rules_cc-${RULES_CC_VERSION}" >> ${WRKDIR}/bazelrc
.endif

	# Bazel must not download wheels, so pypi is replaced with a stub
	# repository that has placeholders for packages the system provides.
	@${MKDIR} ${PYPI_STUB}
	@${PRINTF} 'module(name = "jax_pypi")\n' > ${PYPI_STUB}/MODULE.bazel
	@${TOUCH} ${PYPI_STUB}/REPO.bazel
	@${PRINTF} 'package(default_visibility = ["//visibility:public"])\nexports_files(["requirements.bzl"])\n' \
		> ${PYPI_STUB}/BUILD.bazel
.for _pkg in absl_py build flatbuffers ml_dtypes numpy opt_einsum packaging scipy setuptools wheel
	@${MKDIR} ${PYPI_STUB}/${_pkg}
	@${PRINTF} 'package(default_visibility = ["//visibility:public"])\npy_library(name = "pkg", srcs = [])\nalias(name = "${_pkg}", actual = ":pkg")\n' \
		> ${PYPI_STUB}/${_pkg}/BUILD.bazel
.endfor
	@${MKDIR} ${PYPI_STUB}/numpy/include
	@${LN} -sf ${PYTHON_SITELIBDIR}/numpy/_core/include/numpy ${PYPI_STUB}/numpy/include/numpy
	@${PRINTF} 'cc_library(\n    name = "numpy_headers",\n    hdrs = glob(["include/**/*.h"]),\n    includes = ["include"],\n)\n' \
		>> ${PYPI_STUB}/numpy/BUILD.bazel

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} \
		bazel ${BAZEL_ARGS} build //jaxlib/tools:jaxlib_wheel
	@${MKDIR} ${WRKDIR}/whl
	@${CP} ${WRKSRC}/bazel-bin/jaxlib/tools/dist/*.whl ${WRKDIR}/whl/

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@${UNZIP_NATIVE_CMD} -d ${STAGEDIR}${PYTHON_SITELIBDIR} ${WRKDIR}/whl/${PORTNAME}-*.whl
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaxlib/libjax_common.so

post-install: # autoplist: all files are under ${PYTHON_SITELIBDIR}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|^${LOCALBASE}/||} -type f -or -type l >> ${TMPPLIST}

# jaxlib has no tests of its own, so this runs jax (taken from the same
# source tree) on the staged jaxlib
do-test:
	@cd ${WRKDIR} && ${SETENV} \
		PYTHONPATH=${WRKSRC}:${STAGEDIR}${PYTHON_SITELIBDIR} \
		${PYTHON_CMD} ${FILESDIR}/smoke-test.py

# tests as of 0.12.0.1: jaxlib 0.12.0.1 OK
# the main testsuite is in math/py-jax which is a separate port, so we only run a smoke test here

.include <bsd.port.post.mk>
