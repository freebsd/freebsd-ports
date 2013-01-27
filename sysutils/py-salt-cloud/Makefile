# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	salt-cloud
PORTVERSION=	0.8.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Provisioning salted minions to various cloud providers

LICENSE=	AL2

FETCH_ARGS=	-pRr
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	yes

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

MAN1=		salt-cloud.1
MAN7=		salt-cloud.7

BUILD_DEPENDS+=	salt:${PORTSDIR}/sysutils/salt \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0:${PORTSDIR}/net/py-libcloud \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:${PORTSDIR}/security/py-paramiko \

RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
