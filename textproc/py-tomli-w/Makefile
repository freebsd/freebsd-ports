PORTNAME=	tomli-w
PORTVERSION=	1.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tomli_w-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lil' TOML writer
WWW=		https://github.com/hukkin/tomli-w

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2.0<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
