PORTNAME=	securesystemslib
DISTVERSION=	1.3.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Cryptographic and general-purpose routines
WWW=		https://github.com/secure-systems-lab/securesystemslib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>0:devel/py-asn1crypto@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist cryptography pep517 pytest

SHEBANG_FILES=	securesystemslib/_vendor/test-ed25519-upstream.sh \
	securesystemslib/hash.py \
	securesystemslib/formats.py

NO_ARCH=	yes
TEST_ARGS=	tests

post-patch:
	@${REINPLACE_CMD} -e 's|hatchling==|hatchling>=|g' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
