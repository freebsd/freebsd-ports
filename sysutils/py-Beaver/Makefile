# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	Beaver
PORTVERSION=	29
PORTREVISION=	5
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	logshipper written in Python for logstash

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
USE_RC_SUBR=	beaver

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}conf_d>=0:${PORTSDIR}/textproc/py-conf_d \
	${PYTHON_PKGNAMEPREFIX}glob2>=0:${PORTSDIR}/textproc/py-glob2 \
	${PYTHON_PKGNAMEPREFIX}msgpack>=0:${PORTSDIR}/devel/py-msgpack \
	${PYTHON_PKGNAMEPREFIX}daemon>=0:${PORTSDIR}/devel/py-daemon \
	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

USERS=	beaver
GROUPS=	beaver
OPTIONS_DEFINE=	PIKA ZEROMQ REDIS
OPTIONS_DEFAULT=	ZEROMQ

PIKA_DESC=	AMQP output
ZEROMQ_DESC=	ZEROMQ output
REDIS_DESC=	Redis output

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIKA}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pika>=0:${PORTSDIR}/devel/py-pika
.endif

.if ${PORT_OPTIONS:MZEROMQ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyzmq>=0:${PORTSDIR}/devel/py-pyzmq
.endif

.if ${PORT_OPTIONS:MREDIS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}redis>=0:${PORTSDIR}/databases/py-redis
.endif

# TODO
# - create mosquitto port
.include <bsd.port.mk>
