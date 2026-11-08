PORTNAME=	crazy-complete
DISTVERSION=	0.3.9
CATEGORIES=	shells sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Generate shell auto completion files
WWW=		https://github.com/crazy-complete/crazy-complete

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
