PORTNAME=	pytorch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/pytorch/pytorch/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} # the main tarball disappears when GH_xx tags are added w/out this line
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Tensors and dynamic neural networks in Python
WWW=		https://pytorch.org/ \
		https://github.com/pytorch/pytorch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	build fails: CMake Error at third_party/QNNPACK/CMakeLists.txt:47 (MESSAGE): Unrecognized CMAKE_SYSTEM_NAME = FreeBSD, see https://github.com/pytorch/pytorch/issues/144608
BROKEN_armv7=	build fails: CMake Error at third_party/QNNPACK/CMakeLists.txt:47 (MESSAGE): Unrecognized CMAKE_SYSTEM_NAME = FreeBSD, see https://github.com/pytorch/pytorch/issues/144608
BROKEN_i386=	build fails: DispatchStub.cpp:162:29: [0m[0;1;31merror: [0m[1muse of undeclared identifier 'AVX2'[0m

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		cmake:devel/cmake-core \
		gmake:devel/gmake \
		pybind11>0:devel/pybind11 \
		${PYNUMPY} \
		${LOCALBASE}/include/fxdiv.h:devel/fxdiv \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}optree>0:devel/py-optree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.13.3:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libblis.so:math/blis \
		libmpi_cxx.so:net/openmpi4 \
		libonnx.so:misc/onnx \
		libopenblas.so:math/openblas \
		libpthreadpool.so:devel/pthreadpool \
		libprotobuf.so:devel/protobuf \
		libsleef.so:math/sleef
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>0:filesystems/py-fsspec@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.13.3:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}astunparse>0:devel/py-astunparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} # optional dependencies

USES=		compiler:c++17-lang localbase:ldflags python
USE_PYTHON=	pep517 autoplist
USE_LDCONFIG=	${PYTHON_SITELIBDIR}/torch/lib

# The Python package is named "torch" not "pytorch"
PYDISTUTILS_PKGNAME=	torch
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/torch-${DISTVERSION}*.whl

USE_GITHUB=	nodefault
GH_TUPLE=	pytorch:cpuinfo:1e83a2f:cpuinfo/cpuinfo-with-freebsd-support # https://github.com/pytorch/cpuinfo/pull/230/commits

MAKE_ENV=	USE_NINJA=no # ninja breaks for some reason
MAKE_ENV+=	BUILD_TEST=0 # ninja breaks for some reason
MAKE_ENV+=	USE_MKLDNN=0 # disable MKLDNN that doesn't exist, see https://github.com/pytorch/pytorch/issues/100957
MAKE_ENV+=	USE_CUDNN=0
MAKE_ENV+=	USE_LAPACK=1 # needed on FreeBSD to run w/out GPU
MAKE_ENV+=	USE_QNNPACK=0
MAKE_ENV+=	USE_DISTRIBUTED=1
LDFLAGS+=	-lexecinfo
LDFLAGS_powerpc64le=	-pthread

BINARY_ALIAS=	make=${GMAKE}

POST_PLIST=	fix-plist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN # VULKAN is experimental in PyTorch and only simple computations work

VULKAN_MAKE_ENV=	USE_VULKAN=1 USE_VULKAN_SHADERC_RUNTIME=1 USE_VULKAN_WRAPPER=0 # see https://docs.pytorch.org/tutorials/unstable/vulkan_workflow.html
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:max=15
.endif

post-patch:
	@cd ${WRKSRC} && \
		${RM} -r third_party/cpuinfo third_party/fbgemm/external/cpuinfo && \
		${CP} -r cpuinfo-with-freebsd-support third_party/cpuinfo && \
		${CP} -r cpuinfo-with-freebsd-support third_party/fbgemm/external/cpuinfo

do-install: # port should be moved to 'torch', but keep this for now with the hardcoded 'torch' name
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PEP517_INSTALL_CMD}
	@${PYTHON_CMD} -B ${PORTSDIR}/Mk/Scripts/strip_RECORD.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/torch-${DISTVERSION}*.dist-info/RECORD >> ${_PYTHONPKGLIST}
	@${REINPLACE_CMD} \
		-e '/\.pyc$$/d' \
		-e 's|^|${PYTHONPREFIX_SITELIBDIR}/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../etc/|etc/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../bin/|bin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../include/|include/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../lib/|lib/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libdata/|libdata/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libexec/|libexec/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../man/|man/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../sbin/|sbin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../share/|share/|' \
			${_PYTHONPKGLIST}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} lib -name '*.pyc' >> ${_PYTHONPKGLIST}

fix-plist: # remove the stray %%PYTHON_SITELIBDIR%%/caffe2 file
	@${REINPLACE_CMD} -e "s|.*/caffe2$$||" ${TMPPLIST}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_test.py

.include <bsd.port.mk>
