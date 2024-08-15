PORTNAME=	aiohappyeyeballs
PORTVERSION=	2.3.4
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Happy Eyeballs for asyncio
WWW=		https://aiohappyeyeballs.readthedocs.io/en/latest/ \
		https://github.com/aio-libs/aiohappyeyeballs

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
