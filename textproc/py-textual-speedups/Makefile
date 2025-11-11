PORTNAME=	textual-speedups
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	textual_speedups-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optional Rust speedups for Textual
WWW=		https://github.com/willmcgugan/textual-speedups

#LICENSE=	MIT
#LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.8<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/textual_speedups-${PORTVERSION}

.include <bsd.port.mk>
