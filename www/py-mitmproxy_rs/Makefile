PORTNAME=	mitmproxy_rs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.15
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Rust bits in mitmproxy
WWW=		https://github.com/mitmproxy/mitmproxy_rs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	mitmproxy

BUILD_WRKSRC=	${WRKSRC}/mitmproxy-rs

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/Cargo.lock
CARGO_CARGOTOML=${BUILD_WRKSRC}/Cargo.toml
CARGO_INSTALL=	no

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
