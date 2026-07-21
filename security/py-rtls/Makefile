PORTNAME=	rtls
PORTVERSION=	2026.5.30
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	rtls-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Drop-in replacement for Python's ssl module, backed by rustls
WWW=		https://github.com/jawah/rtls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.2<2.0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wassima>=1<3:security/py-wassima@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_CARGOTOML=${WRKSRC}/rust/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/rust/Cargo.lock
CARGO_INSTALL=	no

.include <bsd.port.mk>
