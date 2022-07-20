PORTNAME=	PyNE
DISTVERSION=	0.7.7
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://raw.githubusercontent.com/pyne/data/master/:decay \
		http://raw.githubusercontent.com/pyne/data/master/:cram \
		http://raw.githubusercontent.com/pyne/data/master/:dlc \
		http://raw.githubusercontent.com/pyne/data/master/:clc \
		https://github.com/pyne/data/raw/master/:nuc_data
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	decay.tar.gz:decay \
		cram.tar.gz:cram \
		decay-linux-clang.tar.gz:dlc \
		cram-linux-clang.tar.gz:clc \
		prebuilt_nuc_data.h5:nuc_data
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyNE: The Nuclear Engineering Toolkit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}tables>0:devel/py-tables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
BUILD_DEPENDS=	cmake:devel/cmake \
		${PY_DEPENDS}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libMOAB.so:math/moab \
		libsz.so:science/libaec
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler:c++17-lang fortran python:3.7+
USE_PYTHON=	distutils cython flavors

USE_GITHUB=	yes
GH_ACCOUNT=	pyne
GH_PROJECT=	pyne

MAKE_ENV=	DESTDIR=${STAGEDIR}
FFLAGS+=	-fallow-argument-mismatch

# all arguments are described here: http://pyne.io/install/source.html#source
PY_EXTRA_ARGS=	--slow	# this chooses slow compilation of sources from {decay,cram}.tar.gz
			# over incompatible pre-compiled assembly from {decay,cram}-linux-clang.tar.gz
PY_EXTRA_ARGS+=	${_MAKE_JOBS}
PY_EXTRA_ARGS+=	--hdf5 ${LOCALBASE}
PY_EXTRA_ARGS+=	--moab ${LOCALBASE}

PYDISTUTILS_CONFIGUREARGS=	${PY_EXTRA_ARGS}
PYDISTUTILS_BUILDARGS=		${PY_EXTRA_ARGS}

BINARY_ALIAS=	python=${PYTHON_CMD}

post-extract:
.for f in decay.tar.gz cram.tar.gz decay-linux-clang.tar.gz cram-linux-clang.tar.gz
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}/src
.endfor

do-install:
	# install project
	cd ${INSTALL_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET}
	# also install nuc_data.h5 because it is referred to in the code and is required by Jupyter notebooks
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/prebuilt_nuc_data.h5 ${STAGEDIR}${PYTHON_SITELIBDIR}/pyne/nuc_data.h5
	# strip
	${STRIP_CMD} \
		${STAGEDIR}${LOCALBASE}/lib/lib*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pyne/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pyne/xs/models.so

.include <bsd.port.mk>
