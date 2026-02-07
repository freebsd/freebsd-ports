PORTNAME=	typst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.7
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Python binding to typst
WWW=		https://github.com/messense/typst-py \
		https://pypi.org/project/typst

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python ssl
USE_GITHUB=	yes
GH_ACCOUNT=	messense
GH_PROJECT=	typst-py
USE_PYTHON=	autoplist pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

.include <bsd.port.mk>
