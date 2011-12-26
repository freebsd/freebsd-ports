# New ports collection makefile for: salt
# Date created:		2011-12-26
# Whom:			Christer Edwards <christer.edwards@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	salt
PORTVERSION=	0.9.4
CATEGORIES=	sysutils python
MASTER_SITES=	https://github.com/downloads/saltstack/salt/

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Distributed, remote execution and configuration management system

LICENSE=	ASL

LIB_DEPENDS=	zmq.1:${PORTSDIR}/devel/zmq

FETCH_ARGS=	-pRr
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=yes

USE_RC_SUBR=	salt_master \
		salt_minion \
		salt_syndic

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	pkg-message

MAN1=		salt-call.1 \
		salt-cp.1 \
		salt-key.1 \
		salt-master.1 \
		salt-minion.1 \
		salt-run.1 \
		salt-syndic.1 \
		salt.1

MAN7=		salt.7

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.9:${PORTSDIR}/devel/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0:${PORTSDIR}/security/py-m2crypto

RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py
	${MV} ${WRKSRC}/conf/master ${WRKSRC}/conf/master.sample
	${MV} ${WRKSRC}/conf/minion ${WRKSRC}/conf/minion.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
