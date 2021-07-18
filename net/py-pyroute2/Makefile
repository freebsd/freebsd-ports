# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pyroute2
PORTVERSION=	0.6.4
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Netlink library

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache.v2
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL.v2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyroute2.core>=${PORTVERSION}:net/py-pyroute2.core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroute2.ethtool>=${PORTVERSION}:net/py-pyroute2.ethtool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroute2.ipset>=${PORTVERSION}:net/py-pyroute2.ipset@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroute2.ndb>=${PORTVERSION}:net/py-pyroute2.ndb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroute2.nftables>=${PORTVERSION}:net/py-pyroute2.nftables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroute2.nslink>=${PORTVERSION}:net/py-pyroute2.nslink@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SS2
SS2_DESC=	Socket statistics

SS2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.0<6:sysutils/py-psutil@${PY_FLAVOR}

.include <bsd.port.mk>
