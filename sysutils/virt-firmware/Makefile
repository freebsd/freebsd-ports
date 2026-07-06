PORTNAME=	virt-firmware
PORTVERSION=	26.5.4
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
DISTNAME=	virt_firmware-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Collection of tools for edk2 firmware images
WWW=		https://gitlab.com/kraxel/virt-firmware

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
