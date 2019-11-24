# $FreeBSD$

PORTNAME=	tvm
DISTVERSION=	0.6.0.rc0
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
USE_PYTHON=	distutils autoplist
GH_TUPLE=	dmlc:dlpack:0acb731:dlpack/3rdparty/dlpack \
		dmlc:dmlc-core:808f485:dmlc_core/3rdparty/dmlc-core

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

POST_PLIST=	fix-plist # https://github.com/apache/incubator-tvm/issues/4411

post-patch:
	@${REINPLACE_CMD} 's|dll_path = \[\]|dll_path = ["${LOCALBASE}/lib"]|' ${BUILD_WRKSRC}/tvm/_ffi/libinfo.py

fix-plist:
	@${REINPLACE_CMD} -e "s|^tvm.*||" ${TMPPLIST}

post-stage:
	@${RM} -r ${STAGEDIR}${PREFIX}/tvm # see fix-plist
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
