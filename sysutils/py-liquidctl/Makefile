# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liquidctl
PORTVERSION=	1.4.2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cross-platform tool and drivers for liquid coolers and other devices

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# With devel/py-hidraw  we do now have a python interface for hidraw(4)
# but unfortunately liquidctl 1.5.1 fails with:
#
#  AttributeError: module 'hidraw' has no attribute 'enumerate'
#  
# Further investigation is ongoing but any help is welcome.
PORTSCOUT=	skipv:1.5.1

.include <bsd.port.mk>
