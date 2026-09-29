PORTNAME=	pyroute2
PORTVERSION=	0.9.6
CATEGORIES=	net python
MASTER_SITES=	PYPI \
		https://github.com/svinota/pyroute2/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Netlink library
WWW=		https://pyroute2.org/ \
		https://github.com/svinota/pyroute2

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache-2.0
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL-2.0-or-later

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SS2
SS2_DESC=	Socket statistics # pyroute2/netlink/diag/ss2.py

SS2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.0:sysutils/py-psutil@${PY_FLAVOR}

.include <bsd.port.mk>
