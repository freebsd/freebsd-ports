PORTNAME=	lingua-language-detector
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Accurate natural language detection library for long and short text
WWW=		https://github.com/pemistahl/lingua-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.1:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	pemistahl
#GH_PROJECT=	lingua-py
GH_PROJECT=	lingua-rs # there is a repository confusion
GH_TAGNAME=	v1.8.0 # there is a repository confusion, see https://github.com/pemistahl/lingua-py/issues/296

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

.include <bsd.port.mk>
