PORTNAME=	cantera
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	science # chemistry physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical kinetics, thermodynamics, and transport tool suite
WWW=		https://cantera.org \
		https://github.com/Cantera/cantera

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	googletest>0:devel/googletest \
		${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs \
		highfive>0:science/highfive \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libyaml-cpp.so:devel/yaml-cpp

USES=		compiler:c++17-lang eigen:3 gettext-runtime localbase scons
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Cantera
GH_TUPLE=	LLNL:sundials:887af43:sundials/ext/sundials # bundled sundials is only needed for the Octave option
GH_TUPLE+=	cantera:cantera-example-data:1a5d27e:example_data/data/example_data

NO_CCACHE=	yes # ccache breaks scons build for some reason

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
MAKE_ENV=	INSTALL_MANPAGES=y

ALL_TARGET=	build
TEST_TARGET=	test # Multiple failures in the testsuite, see https://github.com/Cantera/cantera/issues/1829

OPTIONS_DEFINE=		OCTAVE PYTHON
OPTIONS_DEFAULT=	PYTHON # OCTAVE is off by default because Octave interface is not a frequently requested feature
OPTIONS_SUB=		yes

OCTAVE_DESC=		Octave support
OCTAVE_MAKE_ARGS=	matlab_toolbox=y matlab_path=${LOCALBASE}
OCTAVE_CXXFLAGS=	-I${LOCALBASE}/include/octave-${OCTAVE_VERSION}/octave
OCTAVE_LIB_DEPENDS=	liboctave.so:math/octave
OCTAVE_SUB_FILES=	pkg-message-octave
OCTAVE_USES=		octave:env
OCTAVE_BROKEN=		Octave support needs to be updated

PYTHON_USES=		python
PYTHON_USES_OFF=	python:env
PYTHON_USE=		PYTHON=cython
PYTHON_MAKE_ARGS=	python_cmd=${PYTHON_CMD} python_package=full
PYTHON_MAKE_ARGS_OFF=	python_package="none"
PYTHON_BUILD_DEPENDS=	${PY_SETUPTOOLS} \
			${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcantera_shared.so.${PORTVERSION}

do-install-PYTHON-on:
	# delete .pyc files to fix the stage reference problem, see https://github.com/Cantera/cantera/issues/1601
	@for f in `${FIND} ${STAGEDIR} -name "*.pyc"`; do \
		${RM} $${f}; \
	done
	# strip
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cantera/_cantera.cpython-${PYTHON_SUFFIX}.so \
		${STAGEDIR}${PREFIX}/lib/libcantera_python3_11.so
	# remove empty dirs
	@${RMDIR} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cantera/__pycache__ \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cantera/with_units/__pycache__

post-patch-OCTAVE-on: # adjust Octave version in SConscript (python styled os.environ['OCTAVE_VERSION'] somehow doesn't work for this)
	@${REINPLACE_CMD} -e "s|, 'bin', 'glnx.*')|, 'lib', 'octave', '${OCTAVE_VERSION}')|" ${WRKSRC}/src/matlab/SConscript

post-install-OCTAVE-on: # adjust .mex file name
	@${MV} \
		${STAGEDIR}${PREFIX}/lib/cantera/matlab/toolbox/ctmethods.mexa64 \
		${STAGEDIR}${PREFIX}/lib/cantera/matlab/toolbox/ctmethods.mex

.include <bsd.port.mk>
