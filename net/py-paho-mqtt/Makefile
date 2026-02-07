PORTNAME=	paho-mqtt
DISTVERSION=	2.1.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	paho_mqtt-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MQTT version 3.1/3.1.1 client class
WWW=		https://www.eclipse.org/paho/

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/edl-v10

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_FILES=	examples/*.py

NO_ARCH=	yes

.include <bsd.port.mk>
