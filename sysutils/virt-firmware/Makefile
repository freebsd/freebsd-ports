PORTNAME=	virt-firmware
PORTVERSION=	25.10
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
DISTNAME=	virt_firmware-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Collection of tools for edk2 firmware images
WWW=		https://gitlab.com/kraxel/virt-firmware

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
