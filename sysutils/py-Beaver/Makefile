# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	Beaver
PORTVERSION=	31
PORTREVISION=	4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Logshipper written in Python for logstash

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}conf_d>=0.0.4:textproc/py-conf_d \
	${PYTHON_PKGNAMEPREFIX}glob2>=0:textproc/py-glob2 \
	${PYTHON_PKGNAMEPREFIX}msgpack-python>=0:devel/py-msgpack-python \
	${PYTHON_PKGNAMEPREFIX}daemon>=0:devel/py-daemon \
	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3

USES=	python:2.6+
USE_PYTHON=	distutils autoplist
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
USE_RC_SUBR=	beaver

USERS=	beaver
GROUPS=	beaver
OPTIONS_DEFINE=	PIKA ZEROMQ REDIS SYSLOG_PATCH
OPTIONS_DEFAULT=	ZEROMQ SYSLOG_PATCH

PIKA_DESC=	AMQP output
ZEROMQ_DESC=	ZEROMQ output
REDIS_DESC=	Redis output
SYSLOG_PATCH_DESC=	apply extra patch to support syslog logging

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIKA}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pika>=0:devel/py-pika
.endif

.if ${PORT_OPTIONS:MZEROMQ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq
.endif

.if ${PORT_OPTIONS:MREDIS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis
.endif

.if ${PORT_OPTIONS:MSYSLOG_PATCH}
PLIST_FILES+=	etc/beaver/logging.ini.dist
PLIST_DIRS+=	etc/beaver
.endif

post-patch:
.if ${PORT_OPTIONS:MSYSLOG_PATCH}
	# obtained from https://github.com/josegonzalez/beaver/pull/221.patch
	${PATCH} -d ${WRKSRC} -p1 < ${FILESDIR}/extrapatch-syslog
.endif

post-install:
.if ${PORT_OPTIONS:MSYSLOG_PATCH}
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/beaver
	${INSTALL_DATA} ${WRKSRC}/contrib/logging.ini ${STAGEDIR}/${PREFIX}/etc/beaver/logging.ini.dist
.endif

# TODO
# - create mosquitto port
.include <bsd.port.mk>
