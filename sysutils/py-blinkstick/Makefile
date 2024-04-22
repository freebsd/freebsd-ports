PORTNAME=	blinkstick
DISTVERSION=	g20230504
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BlinkStick-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python package to control BlinkStick USB devices
WWW=		https://pypi.org/project/BlinkStick/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyusb>=1.2.1:devel/py-pyusb@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	arvydas
GH_PROJECT=	${PORTNAME}-python
GH_TAGNAME=	8140b9fa
USE_PYTHON=	autoplist distutils

PLIST_FILES=	etc/devd/blinkstick-devices.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/blinkstick-devices.conf ${STAGEDIR}${PREFIX}/etc/devd/

.include <bsd.port.mk>
