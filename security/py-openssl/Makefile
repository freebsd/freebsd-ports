# Created by: ijliao
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	20.0.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSL-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python interface to the OpenSSL library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.8:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.0.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>0:devel/py-pretend@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils pythonprefix

NO_ARCH=	yes

CPE_VENDOR=	jean-paul_calderone
CPE_PRODUCT=	py${PORTNAME}

# Use options.mk to use OSVERSION and handle redefine PORTEPOCH
.include <bsd.port.options.mk>

# We need to keep old py-cryptography and py-penssl for 11.x release
# due to outdated OpenSSL version in base
.if ${OPSYS} == FreeBSD && ${SSL_DEFAULT} == "base"
. if ${OSVERSION} >= 1103500 && ${OSVERSION} < 1200085
# 1103500	352193 2019-09-10	11.3-STABLE got OpenSSL 1.0.2t
# 1200085	339270 2018-10-19	12.0-STABLE got OpenSSL 1.1.1
#.sinclude "${.CURDIR}/Makefile.${OPSYS}-${OSREL:R}" 
PORTVERSION=	19.1.0
PORTEPOCH=	1
. endif
.endif

# These tests will be skipped due the following reasons:
#
# * test_connect_refused: Avoid stalling in build environments that don't have
#   a internet connection
# * test_set_verify_callback_exception: Fails on *BSD systems, see also
#   https://github.com/pyca/pyopenssl/issues/656 for further details
#
# The system clock must be in sync otherwise the test "test_verify_with_time"
# will fail.
do-test:
	@cd ${WRKSRC} && ${SET_ENV} LC_ALL=en_US.UTF-8 ${TEST_ENV} \
			PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
			${PYTHON_CMD} -m pytest -rs -v -k \
			'not test_connect_refused and \
		       	not test_set_verify_callback_exception'

.include <bsd.port.mk>
