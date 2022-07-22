PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtvm.so:misc/tvm
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}synr>0:devel/py-synr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils noegginfo

USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	tvm
GH_TUPLE=	dmlc:dlpack:ddeb264:dlpack/3rdparty/dlpack \
		dmlc:dmlc-core:09511cf:dmlc_core/3rdparty/dmlc-core

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

MAKE_ENV+=	FREEBSD_LIBRARY_PATH=${LOCALBASE}/lib

BINARY_ALIAS=	git=false

post-patch:
	@${REINPLACE_CMD} 's|dll_path = \[\]|dll_path = ["${LOCALBASE}/lib"]|' ${WRKSRC}/python/tvm/_ffi/libinfo.py

post-install:
	# strip binaries
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}
	# autoplist because 1) python's autoplist is inaccurate for tvm and 2) because there's the add-on package topi
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|${LOCALBASE}/||} -type f -or -type l > ${TMPPLIST}
	@${ECHO} "bin/tvmc" >> ${TMPPLIST}

# Not clear from docs how to run Python tests, see https://github.com/apache/tvm/issues/12158

.include <bsd.port.mk>
