PORTNAME=	keras
DISTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	math # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning library for Python
WWW=		https://keras.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}absl-py>=1.0.0:devel/py-absl-py \
		${PYTHON_PKGNAMEPREFIX}h5py>=0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.3.5:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras-preprocessing>=1.1.0:math/py-keras-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.14:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.13.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras-applications>=1.0.8:math/py-keras-applications@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras-preprocessing>=1.1.1:math/py-keras-preprocessing@${PY_FLAVOR}

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}tensorflow>=2.9.0:science/py-tensorflow@${PY_FLAVOR} \
		bazel:devel/bazel5 \
		bash:shells/bash

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	keras-team
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	r2.9

.include "Makefile.MASTER_SITES"

post-patch:
	# don't cache stuff to $HOME/.cache/
	@${MKDIR} ${WRKDIR}/bazel-cache
	@${MKDIR} ${WRKDIR}/bazel-dist

.for file in ${DISTFILES:C/\:(.*)//}
	@${ECHO} "Moving ${file} to ${WRKDIR}/bazel-dist"
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKDIR}/bazel-dist
.endfor

	# place the generate wheel file here
	@${MKDIR} ${WRKDIR}/whl

	# These files are from my tensorflow port
	# if both make it into the port they can be shared

	# copy the toolchain over
	@${CP} -R ${PATCHDIR}/freebsd \
		${WRKSRC}/

	@${CP} ${PATCHDIR}/bazelrc \
		${WRKSRC}/

	#setup localbase
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" \
		${WRKSRC}/freebsd/cc_toolchain_config.bzl \
		${WRKSRC}/.bazelrc \
		${WRKSRC}/bazelrc

	# setup our bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIR%%#${WRKDIR}#" ${WRKSRC}/bazelrc
	@${REINPLACE_CMD} "s#%%BAZEL_DIST%%#${WRKDIR}#" ${WRKSRC}/bazelrc
	@${REINPLACE_CMD} "s#%%PATH%%#${PATH}#" ${WRKSRC}/bazelrc
	@${REINPLACE_CMD} "s#%%PYTHON%%#${PYTHON_CMD}#" ${WRKSRC}/.bazelrc

	# bazel is horrible, it will won't propagated enviroment variable throughout the build
	# and will ignore variables set by us. This causing a lot of issues, especially with python
	# auto generated files will sometimes ignore our py_runtime toolchain and our PYTHON_BIN_PATH
	# causing it to still set the shebang line to bin/env python3. Even on the github page the solution
	# has been to use a symlink to work around so do that here as a fix
	@${MKDIR} ${WRKDIR}/.bin
	${LN} -s ${PYTHON_CMD} ${WRKDIR}/.bin/python3

	@${REINPLACE_CMD} "s#%%PYTHON%%#${PYTHON_CMD}#" \
		${WRKSRC}/keras/tools/pip_package/build_pip_package.sh

do-build:
	@cd ${WRKSRC} && ${SETENV} \
		PYTHON_BIN_PATH=${PYTHON_CMD} \
		PYTHON_LIB_PATH="${PYTHON_SITELIBDIR}" \
		PYTHON_BINARY=${PYTHON_CMD} \
		bazel --bazelrc="${WRKSRC}/bazelrc" \
		build --config=freebsd \
		//keras/tools/pip_package:build_pip_package

#	@${REINPLACE_CMD} "s#python#${PYTHON_CMD}#" \
#		${WRKSRC}/bazel-bin/keras/tools/pip_package/build_pip_package

	@cd ${WRKSRC} && \
		bazel-bin/keras/tools/pip_package/build_pip_package \
		${WRKDIR}/whl

do-install:
	@${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}

	${UNZIP_NATIVE_CMD} -d ${STAGEDIR}/${PYTHON_SITELIBDIR} ${WRKDIR}/whl/${PORTNAME}-${PORTVERSION}-*.whl

.include <bsd.port.mk>
