PORTNAME=	adasat
DISTVERSIONPREFIX=	v
DISTVERSION=	26.0.0
CATEGORIES=	math devel

MAINTAINER=	ada@FreeBSD.org
COMMENT=	DPLL-based SAT solver in Ada
WWW=		https://github.com/AdaCore/adasat

LICENSE=	APACHE20
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}e3_testsuite>0:devel/py-e3-testsuite@${PY_FLAVOR}

USES=		ada:run python:test
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	AdaSAT
USE_LDCONFIG=	yes

MAKE_CMD=	gprbuild
TEST_ENV=	GPR_PROJECT_PATH=${STAGEDIR}${PREFIX}/share/gpr

NO_SHLIB_REQUIRES_GLOB=	libgnat-${_ada_version}.so

PLIST_SUB=	SO_VERSION=${_SO_VERSION}

_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_PROJECT_ARGS=	-XADASAT_BUILD_MODE=${WITH_DEBUG:Uprod:Dprof}
_SO_VERSION=		${DISTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's|%%SO_VERSION%%|${_SO_VERSION}|' \
		${WRKSRC}/${PORTNAME}.gpr

do-build:
. for _library_type in relocatable static static-pic
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${PORTNAME})
. endfor

do-install:
. for _library_type in relocatable static static-pic
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --build-name=${_library_type} \
		--build-var=${_library_type} --ali-subdir=libdata/${PORTNAME}/${_library_type} \
		--lib-subdir=lib/${PORTNAME}/${_library_type} --sources-subdir=include/${PORTNAME} \
		-XLIBRARY_TYPE=${_library_type} -P ${PORTNAME})
. endfor
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.so -exec ${STRIP_CMD} {} \
		\;

do-test:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} ${PYTHON_CMD} testsuite/testsuite.py)

.include <bsd.port.mk>
