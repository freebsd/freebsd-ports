PORTNAME=	badkeys
DISTVERSION=	0.0.11
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Tool to check public keys for known vulnerabilities
WWW=		https://github.com/badkeys/badkeys

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SSH URLLOOKUP

URLLOOKUP_DESC=	Lookup keys also in URLs

SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR}
URLLOOKUP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}binary_file_search>0:devel/py-binary_file_search@${PY_FLAVOR}

.include <bsd.port.mk>
