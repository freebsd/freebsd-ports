# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	suds-jurko
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight SOAP client (Jurko's fork)

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		dos2unix python tar:bz2
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	# Move the tests into the main package so
	# they are processed by 2to3 so we can test Python 3
	${MV} ${WRKSRC}/tests ${WRKSRC}/suds/tests
	# Compensate for the package/module name change
	${REINPLACE_CMD} -e 's|import tests|import suds.tests|g' \
		${WRKSRC}/suds/tests/test_argument_parser.py \
		${WRKSRC}/suds/tests/test_date_time.py \
		${WRKSRC}/suds/tests/test_input_parameters.py \
		${WRKSRC}/suds/tests/test_reply_handling.py \
		${WRKSRC}/suds/tests/test_request_construction.py \
		${WRKSRC}/suds/tests/test_suds.py \
		${WRKSRC}/suds/tests/test_timezone.py
	${REINPLACE_CMD} -e 's|tests.|suds.tests.|g' \
		${WRKSRC}/suds/tests/conftest.py \
		${WRKSRC}/suds/tests/test_reply_handling.py \
		${WRKSRC}/suds/tests/test_suds.py \
		${WRKSRC}/suds/tests/test_request_construction.py \
		${WRKSRC}/suds/tests/test_input_parameters.py \
		${WRKSRC}/suds/tests/test_argument_parser.py

# lambda: foo needed due to wanting to exclude parametrized tests
# https://github.com/pytest-dev/pytest/issues/5881
# https://github.com/pytest-dev/pytest/issues/6177
#
# Must call tests from the build/ dir because the source dir
# hasn't been processed by 2to3, so tests fail to start on Python 3
#
# Must call the tests from build/lib/suds/tests because
# Defining 'pytest_plugins' in a non-top-level conftest is no longer supported
# https://docs.pytest.org/en/latest/deprecations.html#pytest-plugins-in-non-top-level-conftest-files

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		-k "not test_document_literal_request_for_single_element_input \
		and not (lambda: locals)()()['test_binding_uses_argument_parsing[binding_style1]'] \
		and not (lambda: locals)()()['test_choice_containing_an_empty_sequence[test_args_required0]'] \
		and not (lambda: locals)()()['test_choice_explicitly_marked_as_optional[choice0]'] \
		and not test_sending_unicode_data" \
		build/lib/suds/tests

.include <bsd.port.mk>
