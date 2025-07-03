PORTNAME=	cryptography
PORTVERSION=	44.0.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cryptographic recipes and primitives for Python developers
WWW=		https://cryptography.io/en/latest/ \
		https://github.com/pyca/cryptography

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.12:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maturin>=1<2:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.12:devel/py-cffi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.5:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography-vectors>=${PORTVERSION}<${PORTVERSION}_99:security/py-cryptography-vectors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>=0.7:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=4.0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.10.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=0:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.5.0,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cargo cpe python ssl
USE_PYTHON=	autoplist concurrent pep517 pytest

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/src/rust/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/src/rust/Cargo.toml
CARGO_INSTALL=	no
CARGO_TEST=	no
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

CPE_VENDOR=	cryptography_project

OPTIONS_DEFINE=	SSH

SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.5:security/py-bcrypt@${PY_FLAVOR}

.include <bsd.port.mk>
