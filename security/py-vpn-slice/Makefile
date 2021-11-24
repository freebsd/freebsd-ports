PORTNAME=	vpn-slice
DISTVERSION=	0.15
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Customized VPN split-tunnel

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.16:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.2:devel/py-setproctitle@${PY_FLAVOR}

USES=		python:3.3+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
