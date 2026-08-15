PORTNAME=	fqdn
DISTVERSION=	1.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	whitejv81@gmail.com
COMMENT=	RFC-compliant FQDN validation and manipulation for Python
WWW=		https://github.com/ypcrts/fqdn

LICENSE=	MPL20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
