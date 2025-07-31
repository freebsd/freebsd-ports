PORTNAME=	nh3
DISTVERSION=	0.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
# Workaround to use both the PyPI tarball and the cargo crates.
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Python Bindings to the ammonia HTML sanitization library
WWW=		https://github.com/messense/nh3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
