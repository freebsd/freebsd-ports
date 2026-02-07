PORTNAME=	salt-tower
DISTVERSION=	1.12.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereckson@gmail.com
COMMENT=	External pillar to manage and merge a stack of pillars
WWW=		https://jgraichen.github.io/salt-tower/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-pep517>0:devel/py-pdm-pep517@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
