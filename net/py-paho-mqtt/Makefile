PORTNAME=	paho-mqtt
PORTVERSION=	1.6.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	MQTT version 3.1/3.1.1 client class
WWW=		https://www.eclipse.org/paho/

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/edl-v10

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	examples/*.py

NO_ARCH=	yes

.include <bsd.port.mk>
