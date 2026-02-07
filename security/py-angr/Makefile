PORTNAME=	angr
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
PORTREVISION=	5
CATEGORIES=	security devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-architecture binary analysis toolkit
WWW=		https://github.com/angr/angr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvex>=${ANGR_VERSION}:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR}
LIB_DEPENDS=	libunicorn.so:emulators/unicorn \
		libz3.so:math/z3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ailment>=${ANGR_VERSION}:security/py-ailment@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}capstone>=3.0.5:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.14.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}claripy>=${ANGR_VERSION}:math/py-claripy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cle>=${ANGR_VERSION}:devel/py-cle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cppheaderparser>=0:devel/py-cppheaderparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:net/py-dpkt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itanium_demangler>=0:devel/py-itanium_demangler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mulpyplexer>=0:devel/py-mulpyplexer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar2>=0:misc/py-progressbar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.12.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>2.18:devel/py-pycparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${ANGR_VERSION}:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpyc>0:devel/py-RPyC@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keystone-engine>=0:devel/py-keystone-engine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		angr:binaries gmake localbase:ldflags python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

TEST_ENV=	${MAKE_ENV} \
		NOSE_EXCLUDE="${_NOSE_EXCLUDE}"

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
# Problem: the test is hanging
_EXCLUDED_TESTS+=	test_veritesting_a
# There are far more tests which are failing at the moment...

# Create a regular expression out of the excluded tests,
# but first remove double spaces.
_NOSE_EXCLUDE=	(${_EXCLUDED_TESTS:S,  , ,g:S, ,|,gW})

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/lib/angr_native*.so

do-test:
	@(cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v)

.include <bsd.port.mk>
