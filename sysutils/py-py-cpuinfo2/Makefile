PORTNAME=	py-cpuinfo2
PORTVERSION=	10.1.1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_cpuinfo2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get CPU info with pure Python
WWW=		https://github.com/akx/py-cpuinfo2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
