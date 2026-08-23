PORTNAME=       biscuit-python
DISTVERSION=    0.4.0
PORTREVISION=	3
CATEGORIES=     security python
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=     joneum@FreeBSD.org
COMMENT=        Python bindings for Biscuit authorization tokens
WWW=            https://github.com/eclipse-biscuit/biscuit-python

LICENSE=        APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}maturin>=1<2:devel/py-maturin@${PY_FLAVOR}

USES=           cargo python
USE_GITHUB=     yes
GH_ACCOUNT=     eclipse-biscuit
GH_TAGNAME=     ${DISTVERSION}
USE_PYTHON=     autoplist concurrent pep517

CARGO_BUILD=    no
CARGO_INSTALL=  no

MAKE_ENV+=	${CARGO_ENV}

PEP517_BUILD_CONFIG_SETTING=	-C "maturin.build-args=--strip"

.include "${.CURDIR}/Makefile.crates"
.include <bsd.port.mk>
