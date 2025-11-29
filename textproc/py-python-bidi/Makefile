PORTNAME=	python-bidi
DISTVERSION=	0.6.7
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Bidi layout wrapping the Rust crate unicode-bidi
WWW=		https://github.com/MeirKriheli/python-bidi

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist concurrent pytest

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TEST_ARGS=	--no-default-features

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
#TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
