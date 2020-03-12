# $FreeBSD$

PORTNAME=	angr
DISTVERSION=	8.20.1.7
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Multi-architecture binary analysis toolkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvex>=${DISTVERSION}:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR}
LIB_DEPENDS=	libunicorn.so:emulators/unicorn
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ailment>=${DISTVERSION}:security/py-ailment@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}capstone>=3.0.5:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.7.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}claripy>=${DISTVERSION}:math/py-claripy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cle>=${DISTVERSION}:devel/py-cle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:net/py-dpkt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GitPython>=0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itanium_demangler>=0:devel/py-itanium_demangler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mulpyplexer>=0:devel/py-mulpyplexer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar2>=0:misc/py-progressbar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>2.18:devel/py-pycparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpyc>0:devel/py-RPyC@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystone-engine>=0:devel/py-keystone-engine@${PY_FLAVOR} \
		z3>=0:math/z3

USES=		gmake localbase python:3.5+
USE_GITHUB=	nodefault
GH_TUPLE=	${PORTNAME}:${PORTNAME}:6b1a0825cbe156e2d32c577ba47ff50920f005aa:tests \
		${PORTNAME}:binaries:f2de6d7a0474d22130ffadd042327536a6fda114:binaries
USE_PYTHON=	autoplist distutils

TEST_ENV=	${MAKE_ENV} NOSE_EXCLUDE="${_NOSE_EXCLUDE}"

# Problem: the following tests require PySoot: https://github.com/angr/pysoot
_EXCLUDED_TESTS+=	test_simple1
_EXCLUDED_TESTS+=	test_simple2
_EXCLUDED_TESTS+=	test_fauxware
_EXCLUDED_TESTS+=	test_cmd_line_args
_EXCLUDED_TESTS+=	test_jni_version_information
_EXCLUDED_TESTS+=	test_jni_global_and_local_refs
_EXCLUDED_TESTS+=	test_jni_object_operations
_EXCLUDED_TESTS+=	test_jni_string_operations
_EXCLUDED_TESTS+=	test_jni_field_access
_EXCLUDED_TESTS+=	test_jni_method_calls
_EXCLUDED_TESTS+=	test_jni_primitive_datatypes
_EXCLUDED_TESTS+=	test_jni_object_arrays
_EXCLUDED_TESTS+=	test_jni_array_operations
_EXCLUDED_TESTS+=	test_method_calls
_EXCLUDED_TESTS+=	test_array_operations
_EXCLUDED_TESTS+=	test_multiarray_operations
_EXCLUDED_TESTS+=	test_loading
_EXCLUDED_TESTS+=	test_toggling_of_simstate
# Problem: "TypeError: %d format: a number is required, not NoneType"
_EXCLUDED_TESTS+=	test_fastmem.*
# Problem: "angr.errors.AngrIncongruencyError: Different constraints!"
_EXCLUDED_TESTS+=	test_similarity_fauxware
# Problem: "IndexError: list index out of range"
_EXCLUDED_TESTS+=	test_self_modifying_code
# Problem: "Exception: Not a valid binary file: '/bin/false'"
_EXCLUDED_TESTS+=	test_project

# Create a regular expression out of the excluded tests.
_NOSE_EXCLUDE=	(${_EXCLUDED_TESTS:S, ,|,gW})

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' \
		-e 's|%%CXX%%|${CXX}|g' \
		-e 's|%%CFLAGS%%|${CFLAGS}|g' \
		-e 's|%%LDFLAGS%%|${LDFLAGS}|g' \
		-e 's|%%LIBS%%|${LIBS}|g' \
		${WRKSRC}/native/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/lib/angr_native.so

pre-test:
	@${LN} -Fs ${WRKSRC_tests}/tests ${WRKSRC}/tests
	@${LN} -Fs ${WRKSRC_binaries} ${WRKDIR}/binaries

do-test:
	@(cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v)

.include <bsd.port.mk>
