PORTNAME=	jh2
PORTVERSION=	5.0.9
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/jawah/h2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2 State-Machine based protocol implementation
WWW=		https://python-hyper.org/projects/h2/en/stable/ \
		https://github.com/jawah/h2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.7<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

.include <bsd.port.mk>
