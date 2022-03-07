# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	cryptography
PORTVERSION=	3.3.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
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
USES=		cpe compiler:env python:3.6+ ssl
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist concurrent distutils

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.pre.mk>

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
