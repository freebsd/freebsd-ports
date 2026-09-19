PORTNAME=	slixmpp
DISTVERSION=	1.17.0
CATEGORIES=	net-im python
MASTER_SITES=	PYPI
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lazeraman@gmail.com
COMMENT=	Elegant Python library for XMPP (aka Jabber)
WWW=		https://slixmpp.readthedocs.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>=0:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emoji>=0:misc/py-emoji@${PY_FLAVOR} \
		gpg:security/gnupg

USES=		cargo cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

OPTIONS_DEFINE=	EMOJI HTTP OMEMO SAFEXML
EMOJI_DESC=	Enables emoji support (xep-0444)
HTTP_DESC=	Enables HTTP file upload support (xep-0363)
OMEMO_DESC=	Enables OMEMO media sharing support (xep-0454)
SAFEXML_DESC=	Enables Safer XML Parsing

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR}
EMOJI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}emoji>=0:misc/py-emoji@${PY_FLAVOR}
OMEMO_USE=		PYTHON=cryptography
SAFEXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py

.include <bsd.port.mk>
