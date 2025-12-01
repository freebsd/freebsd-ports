PORTNAME=	unicode-segmentation-rs
PORTVERSION=	0.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	unicode_segmentation_rs-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unicode segmentation and width for Python using Rust
WWW=		https://github.com/WeblateOrg/unicode-segmentation-rs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.10.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/unicode_segmentation_rs-${PORTVERSION}

.include <bsd.port.mk>
