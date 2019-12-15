# $FreeBSD$

PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtvm.so:misc/tvm
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-tvm
USE_PYTHON=	distutils noegginfo
GH_TUPLE=	dmlc:dlpack:0acb731:dlpack/3rdparty/dlpack \
		dmlc:dmlc-core:808f485:dmlc_core/3rdparty/dmlc-core

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python
BUILD_WRKSRC_TOPI=	${WRKSRC}/topi/python
INSTALL_WRKSRC_TOPI=	${WRKSRC}/topi/python

MAKE_ENV+=	FREEBSD_LIBRARY_PATH=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|dll_path = \[\]|dll_path = ["${LOCALBASE}/lib"]|' ${WRKSRC}/python/tvm/_ffi/libinfo.py

post-configure:
	@cd ${BUILD_WRKSRC_TOPI} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_CONFIGURE_TARGET} ${PYDISTUTILS_CONFIGUREARGS}

post-build:
	@cd ${BUILD_WRKSRC_TOPI} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS}

post-install:
	@cd ${INSTALL_WRKSRC_TOPI} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS}
	@${RM} -r ${STAGEDIR}${PREFIX}/tvm ${STAGEDIR}${PREFIX}/topi
	@${RM} ${STAGEDIR}${PREFIX}/topi/libtvm_topi.so
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}
	# autoplist because 1) python's autoplist is inaccurate for tvm and 2) because there's the add-on package topi
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${PYTHON_SITELIBDIR:C|${LOCALBASE}/||} -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
