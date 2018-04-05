# $FreeBSD$

PORTNAME=	netmiko
DISTVERSION=	2.1.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Multi-vendor library to simplify SSH connections to network devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=2.0.0:security/py-paramiko@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serial>0:comms/py-serial@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.10.0:security/py-scp@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>0:textproc/py-textfsm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
