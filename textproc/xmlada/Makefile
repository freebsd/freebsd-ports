PORTNAME=	xmlada
DISTVERSIONPREFIX=	v
DISTVERSION=	26.0.0
CATEGORIES=	textproc
MASTER_SITES=	${_TEST_SITE_XMLTS} \
		${_TEST_SITE_XSTS}
DISTFILES=	${_TEST_DIST_XMLTS}:test_xmlts \
		${_TEST_DIST_XSTS}:test_xsts

MAINTAINER=	ada@FreeBSD.org
COMMENT=	XML/Ada toolkit
WWW=		https://docs.adacore.com/live/wave/xmlada/html/xmlada_ug/intro.html

LICENSE=	GPLv3+ GPLv3RLE+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		gprbuild>=25:devel/gprbuild \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
TEST_DEPENDS=	gmake:devel/gmake

USES=		ada:run python:build
USE_BINUTILS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore

MAKE_CMD=	gprbuild

TEST_ENV=	GPR_PROJECT_PATH=${STAGEDIR}${PREFIX}/share/gpr

NO_SHLIB_REQUIRES_GLOB=	libgnat-${_ada_version}.so

PLIST_SUB=	SO_VERSION=${DISTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=			DOCS EXAMPLES
OPTIONS_DEFAULT=		PRODUCTION
OPTIONS_RADIO=			BUILDTYPE
OPTIONS_RADIO_BUILDTYPE=	COVERAGE DEBUG PRODUCTION PROFILE

BUILDTYPE_DESC=		Application production type
COVERAGE_DESC=		Produce instrumentation data for analysis
DEBUG_DESC=		Produce symbols for debugging
DOCS_DESC=		Install extensive online HTML documentation
PRODUCTION_DESC=	Produce for release/production
PROFILE_DESC=		Produce instrumentation data for profiling

COVERAGE_VARS=		_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=coverage
DEBUG_VARS=		_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=Debug
PRODUCTION_VARS=	_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=Production
PROFILE_VARS=		_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=profile

_DOCS_INSTALL_EXCLUDES=	"-not -name .buildinfo -not -regex ^./_sources.*"
_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -p -vh -vP2 \
			-XPROCESSORS=${MAKE_JOBS_NUMBER}
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_PROJECT_ARGS=	-XXMLADA_BUILD_MODE=${WITH_DEBUG:UProduction:DDebug}
_TEST_DIST_XMLTS=	xmlts20080827.tar
_TEST_DIST_XSTS=	xsts-2007-06-20.tar.gz
_TEST_SITE_XMLTS=	https://www.w3.org/XML/Test/:test_xmlts
_TEST_SITE_XSTS=	https://www.w3.org/XML/2004/xml-schema-test-suite/xmlschema2006-11-06/:test_xsts
_TESTS_GPRBUILD_ARGS=	-q -XPROCESSORS=${MAKE_JOBS_NUMBER}

post-patch:
	${REINPLACE_CMD} -e 's|@PACKAGE_VERSION@|${DISTVERSION}|' \
		-e 's|@SO_EXT@|.so|' \
		${WRKSRC}/${PORTNAME}_shared.gpr.in
# Set defaults for do-test. These two Types are still external and will still
# reflect the OPTION helpers above
	${REINPLACE_CMD} -e 's|@DEFAULT_LIBRARY_TYPE@|static|' \
		-e 's|@BUILD_TYPE@|${_GPR_PROJECT_ARGS:C/.*=//}|' \
		${WRKSRC}/${PORTNAME}_shared.gpr.in
	${REINPLACE_CMD} -e 's|@exec_prefix@/||' \
		${WRKSRC}/tests/dom/default.gpr.in
	${REINPLACE_CMD} -e 's|%%TESTS_GPRBUILD_ARGS%%|${_TESTS_GPRBUILD_ARGS}|' \
		${WRKSRC}/tests/Makefile
	${MV} ${WRKSRC}/tests/dom/default.gpr.in \
		${WRKSRC}/tests/dom/default.gpr
	${MV} ${WRKSRC}/${PORTNAME}_shared.gpr.in \
		${WRKSRC}/${PORTNAME}_shared.gpr

do-build:
.for _library_type in relocatable static static-pic
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${PORTNAME})
.endfor
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -d ./doctrees \
		-b man . build/man)

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -d ./doctrees \
		-b html . build/html)

do-install:
. for _xmlada_component in dom sax schema unicode
.  for _library_type in relocatable static static-pic
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --build-name=${_library_type} \
		--build-var=${_library_type} --ali-subdir=libdata/${PORTNAME}/${_xmlada_component}/${_library_type} \
		--lib-subdir=lib/${PORTNAME}/${_xmlada_component}/${_library_type} \
		--sources-subdir=include/${PORTNAME}/${_xmlada_component} \
		-XLIBRARY_TYPE=${_library_type} -P ${_xmlada_component}/${PORTNAME}_${_xmlada_component})
.  endfor
. endfor
# Separate XML/Ada Input from above because the directory name is not
# consistent with the library name
. for _library_type in relocatable static static-pic
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --build-name=${_library_type} \
		--build-var=${_library_type} --ali-subdir=libdata/${PORTNAME}/input/${_library_type} \
		--lib-subdir=lib/${PORTNAME}/input/${_library_type} \
		--sources-subdir=include/${PORTNAME}/input -XLIBRARY_TYPE=${_library_type} \
		-P input_sources/${PORTNAME}_input)
. endfor
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.so.${DISTVERSION} -exec \
		${STRIP_CMD} {} \;

do-install-DOCS-on:
	(cd ${WRKSRC}/docs/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} ${_DOCS_INSTALL_EXCLUDES})

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

pre-test:
	${RLN} ${WRKDIR}/xmlconf ${WRKSRC}/tests/dom/tests
	${RLN} ${WRKDIR}/xmlschema2006-11-06 ${WRKSRC}/tests/schema

do-test:
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} ${MAKE_CMD} ${_GPR_PROJECT_ARGS} \
		${_GPRBUILD_ARGS} -XLIBRARY_TYPE=static -XTESTS_ACTIVATED=Only \
		xmlada.gpr)
	(cd ${WRKSRC}/tests && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} -XLIBRARY_TYPE=static \
		-XTESTS_ACTIVATED=Only gmake tests)

.include <bsd.port.mk>
