# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	salt-cloud
PORTVERSION=	0.8.10
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Provisioning salted minions to various cloud providers

LICENSE=	AL2

FETCH_ARGS=	-pRr
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	yes

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

MAN1=		salt-cloud.1
MAN7=		salt-cloud.7

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}salt>=0.13.0:${PORTSDIR}/sysutils/py-salt \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0.11.4:${PORTSDIR}/net/py-libcloud \
		${PYTHON_PKGNAMEPREFIX}botocore>=0:${PORTSDIR}/devel/py-botocore \
		sshpass>=0:${PORTSDIR}/security/sshpass

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
