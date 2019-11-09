# $FreeBSD$

PORTNAME=	tensorflow-estimator
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amzo1337@gmail.com
COMMENT=	TensorFlow Estimator, an API to simplify machine learning programming

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash \
		bazel:devel/bazel029 \
		${PYTHON_PKGNAMEPREFIX}tensorflow>=1.14.0:science/py-tensorflow@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_GLOB=	*.py
USE_GITHUB=	yes
GH_ACCOUNT=	tensorflow
GH_PROJECT=	estimator

NO_ARCH=	yes

BAZEL_BOOT=	--output_user_root=${WRKDIR}/bazel_out

post-patch:
	@${REINPLACE_CMD} "s#%%PYTHON%%#${PYTHON_CMD}#" \
		${WRKSRC}/tensorflow_estimator/tools/pip_package/build_pip_package.sh

do-build:
	@cd ${WRKSRC} && \
		bazel ${BAZEL_BOOT} build -s \
			//tensorflow_estimator/tools/pip_package:build_pip_package
	@cd ${WRKSRC} && ${SETENV} TMPDIR=${WRKDIR} && \
		bazel-bin/tensorflow_estimator/tools/pip_package/build_pip_package \
			${WRKDIR}/whl

do-install:
	@${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}
	@${MKDIR} ${WRKDIR}/tmp
	@${UNZIP_NATIVE_CMD} -d ${WRKDIR}/tmp ${WRKDIR}/whl/${PORTNAME:S/-/_/}-${PORTVERSION}-*.whl
	cd ${WRKDIR}/tmp && ${COPYTREE_SHARE} ${PORTNAME:S/-/_/} \
		${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR}/tmp && ${COPYTREE_SHARE} ${PORTNAME:S/-/_/}-${PORTVERSION}.dist-info \
		${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
