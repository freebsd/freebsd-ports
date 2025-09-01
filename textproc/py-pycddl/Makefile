PORTNAME=	pycddl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	3
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Deserialize CBOR and/or do CDDL schema validation
WWW=		https://pypi.org/project/${PORTNAME} \
		https://gitlab.com/tahoe-lafs/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_GITLAB=	yes
GL_ACCOUNT=	tahoe-lafs
USE_PYTHON=	autoplist pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_ENV=	PYO3_PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
