PORTNAME=	tokenizers
DISTVERSION=	0.20.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Fast state-of-the-art tokenizers optimized for research and production
WWW=		https://github.com/huggingface/tokenizers

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.16.4<1.0:misc/py-huggingface-hub@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/oniguruma.pc:devel/oniguruma

USES=		cargo python
USE_PYTHON=	autoplist pep517

CARGO_CARGOTOML=${WRKSRC}/bindings/python/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/bindings/python/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type f -name '*.so' -exec ${STRIP_CMD} {} ';'

.include <bsd.port.mk>
