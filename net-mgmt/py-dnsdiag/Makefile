# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>

PORTNAME=	dnsdiag
PORTVERSION=	2.0.2
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	DNS Diagnostics and measurement tools (ping, traceroute)

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython2>=2.0.0:dns/py-dnspython2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cymruwhois>=1.6:net/py-cymruwhois@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.9.1:www/py-requests-toolbelt@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
