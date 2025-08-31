PORTNAME=	PyNE
DISTVERSION=	0.7.8
PORTREVISION=	4
CATEGORIES=	science # physics
MASTER_SITES=	https://raw.githubusercontent.com/pyne/data/master/:decay \
		https://raw.githubusercontent.com/pyne/data/master/:cram \
		https://raw.githubusercontent.com/pyne/data/master/:dlc \
		https://raw.githubusercontent.com/pyne/data/master/:clc \
		https://raw.githubusercontent.com/pyne/data/master/:nuc_data
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
WWW=		https://pyne.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_armv7=	clang runs out of memory

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}progress>0:devel/py-progress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>0:devel/py-tables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>0:devel/py-tables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} # the dependency list is only in ubuntu.sh, see https://github.com/pyne/pyne/issues/1518
PY_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}OpenMC>0:science/py-OpenMC@${PY_FLAVOR}
BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PY_DEPENDS}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libMOAB.so:math/moab
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler:c++17-lang fortran python
USE_PYTHON=	distutils cython flavors

USE_GITHUB=	yes
GH_ACCOUNT=	pyne
GH_PROJECT=	pyne

MAKE_ENV=	DESTDIR=${STAGEDIR}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
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
	# remove stray files
	${RM} ${STAGEDIR}${PREFIX}/bin/ubuntu.sh
	# strip
	${STRIP_CMD} \
		${STAGEDIR}${LOCALBASE}/lib/lib*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pyne/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pyne/xs/models.so

# CAVEAT: due to the failure to find MOAB-5.5.1 the file pyne/source_sampling.so isn't built, and is removed from plist
#         - see https://github.com/pyne/pyne/issues/1537

.include <bsd.port.mk>
