# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	cryptography
PORTVERSION=	3.3.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Cryptographic recipes and primitives for Python developers

LICENSE=			APACHE20 BSD3CLAUSE
LICENSE_COMB=			dual
LICENSE_FILE_APACHE20=		${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.8:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.8:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.1:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography-vectors>=${PORTVERSION}:security/py-cryptography-vectors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=1.11.4:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>0:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.6.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

# Python 2.7, 3.5-3.8
USES=		compiler:env python:3.6+ ssl
USE_PYTHON=	autoplist concurrent distutils

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.pre.mk>

# OpenSSL 1.0.2t got some curve matching parameter code backported before it
# has reached its End-of-Life and security/py-cryptography already had some
# code to handle this case, but it assumed OpenSSL 1.1.0+ .
#
# This has been fixed in 3.0-23-g241f8450 of security/py-cryptography and to be
# clear: It isn't a security fix but rather a workaround to handle unnamed but
# really named curves with OpenSSL 1.0.2t/u .

# We need to keep old py-cryptography and py-openssl for 11.x release
# due to outdated OpenSSL version in base
.if ${OPSYS} == FreeBSD && ${SSL_DEFAULT} == "base"
. if ${OSVERSION} >= 1103500 && ${OSVERSION} < 1200085
# 1103500	352193 2019-09-10	11.3-STABLE got OpenSSL 1.0.2t
# 1200085	339270 2018-10-19	12.0-STABLE got OpenSSL 1.1.1
PORTVERSION=	2.9.2
EXTRA_PATCHES=	${PATCHDIR}/openssl102u
. endif
.endif

# Apply LibreSSL upstream patch that conflicts with above patch for 2.9.2
# XXX convert back to unconditional when FreeBSD 11 goes EOL
.if ${SSL_DEFAULT:Mlibressl*}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-Fix-build-with-LibreSSL-3.3.2-5988
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
post-patch:
	@${REINPLACE_CMD} -e 's|"-Wno-error=sign-conversion"||' \
		${WRKSRC}/src/_cffi_src/build_openssl.py
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cryptography/hazmat/bindings/*.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -q -v -rs -o addopts=

.include <bsd.port.post.mk>
