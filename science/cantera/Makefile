PORTNAME=	cantera
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1-552
DISTVERSIONSUFFIX=	-gcf085e47e
PORTREVISION=	1
CATEGORIES=	science # chemistry physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical kinetics, thermodynamics, and transport tool suite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libsundials_cvodes.so:math/sundials \
		libyaml-cpp.so:devel/yaml-cpp

USES=		compiler:c++11-lang eigen:3 scons
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Cantera

MAKE_ARGS=	system_eigen='y' \
		system_sundials='y' \
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

OPTIONS_DEFINE=		PYTHON

PYTHON_USES=		python
PYTHON_MAKE_ARGS=	python_cmd="${PYTHON_CMD}"
PYTHON_MAKE_ARGS_OFF=	python_package="none"
PYTHON_BROKEN=		installs *.cpython-38.pyc files referring to the stage directory, see https://github.com/Cantera/cantera/issues/1094

do-install:
	cd ${WRKSRC} && \
		${MAKE_CMD} install \
			stage_dir="${STAGEDIR}"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcantera_shared.so.2.6.0

.include <bsd.port.mk>
