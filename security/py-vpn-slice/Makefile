PORTNAME=	vpn-slice
PORTVERSION=	0.16.1
CATEGORIES=	security python net-vpn
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	vpnc-script replacement for easy split-tunnel VPN setup
WWW=		https://github.com/dlenski/vpn-slice

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=0,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=0:devel/py-setproctitle@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
