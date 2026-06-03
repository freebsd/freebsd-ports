PORTNAME=       biscuit-auth
DISTVERSION=    0.4.0
CATEGORIES=     security python
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=     joneum@FreeBSD.org
COMMENT=        Python bindings for Biscuit authorization tokens
WWW=            https://github.com/eclipse-biscuit/biscuit-python

LICENSE=        APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}maturin>=1<2:devel/py-maturin@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}installer>=0:devel/py-installer@${PY_FLAVOR}

USES=           cargo python
USE_GITHUB=     yes
GH_ACCOUNT=     eclipse-biscuit
GH_PROJECT=     biscuit-python
GH_TAGNAME=     ${DISTVERSION}
USE_PYTHON=     autoplist concurrent

CARGO_BUILD=    no
CARGO_INSTALL=  no

CARGO_ENV=      PYO3_PYTHON=${PYTHON_CMD} \
                PYTHON_SYS_EXECUTABLE=${PYTHON_CMD}

MAKE_ENV=       ${CARGO_ENV}

BINARY_ALIAS=   python3=${PYTHON_CMD}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} \
		${PYTHON_CMD} -m maturin build --release --strip --interpreter ${PYTHON_CMD}

do-install:
	cd ${WRKDIR}/target/wheels && \
		${PYTHON_CMD} -m installer --destdir=${STAGEDIR} --prefix=${PREFIX} *.whl

.include "${.CURDIR}/Makefile.crates"
.include <bsd.port.mk>
