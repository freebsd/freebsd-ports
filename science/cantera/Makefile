PORTNAME=	cantera
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1-611
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gc4d6ecc15
CATEGORIES=	science # chemistry physics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	5720ff659f4bd8dad33d32891fe7d4ae44c72697.patch:-p1 \
		36e7019cab8e9d9e8388715b5680fea924ce6f52.patch:-p1 # fix "Fix stage directory from appearing in setup_cantera", https://github.com/Cantera/cantera/pull/1102

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical kinetics, thermodynamics, and transport tool suite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	googletest>0:devel/googletest \
		${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libyaml-cpp.so:devel/yaml-cpp

USES=		compiler:c++11-lang eigen:3 scons
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Cantera
GH_TUPLE=	LLNL:sundials:887af43:sundials/ext/sundials # bundled sundials is only needed for the Octave option

MAKE_ARGS=	system_eigen='y' \
		system_sundials='n' \
		system_fmt='y' \
		system_yamlcpp='y' \
		googletest='system' \
		sundials_include='${LOCALBASE}/include/sundials' \
		extra_inc_dirs="${LOCALBASE}/include:${LOCALBASE}/include/eigen3" \
		extra_lib_dirs="${LOCALBASE}/lib" \
		debug='no' \
		cc_flags="${CXXFLAGS}" \
		prefix="${PREFIX}"

ALL_TARGET=	build
TEST_TARGET=	test # some tests fail, see https://github.com/Cantera/cantera/issues/1095

OPTIONS_DEFINE=		OCTAVE PYTHON
OPTIONS_DEFAULT=	PYTHON # OCTAVE is off by default because Octave interface is not as frequently requested feature
OPTIONS_SUB=		yes

OCTAVE_DESC=		Octave support
OCTAVE_MAKE_ARGS=	matlab_toolbox=y matlab_path=${LOCALBASE}
OCTAVE_CXXFLAGS=	-I${LOCALBASE}/include/octave-6.4.0/octave
OCTAVE_LIB_DEPENDS=	liboctave.so:math/octave
OCTAVE_SUB_FILES=	pkg-message-octave

PYTHON_USES=		python:3.6+
PYTHON_USE=		PYTHON=cython
PYTHON_MAKE_ARGS=	python_cmd=${PYTHON_CMD} python_package=full
PYTHON_MAKE_ARGS_OFF=	python_package="none"
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

do-install:
	cd ${WRKSRC} && \
		${MAKE_CMD} install \
			stage_dir="${STAGEDIR}"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcantera_shared.so.2.6.0

do-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cantera/_cantera.cpython-${PYTHON_VER:S/.//}.so

.include <bsd.port.mk>
