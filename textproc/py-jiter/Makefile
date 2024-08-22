PORTNAME=	jiter
DISTVERSION=	0.5.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Fast iterable JSON parser
WWW=		https://github.com/pydantic/jiter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/crates/jiter/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type f -name '*.so' -exec ${STRIP_CMD} {} ';'

.include <bsd.port.mk>
