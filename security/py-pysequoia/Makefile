PORTNAME=	pysequoia
DISTVERSION=	0.1.35
CATEGORIES=	security
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	polarian@polarian.dev
COMMENT=	Provides OpenPGP facilities using Sequoia-PGP library
WWW=		https://github.com/wiktor-k/pysequoia

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.11.0:devel/py-setuptools-rust@${PY_FLAVOR}

USES=		python:3.7+ cargo
USE_PYTHON=	autoplist pep517 pytest

CARGO_BUILD=no
CARGO_INSTALL=no
CARGO_TEST=no
CARGO_CARGOTOML=${WRKSRC}/Cargo.toml

.include <bsd.port.mk>
