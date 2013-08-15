# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	Beaver
PORTVERSION=	29
#PORTREVISION=	0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	logshipper written in Python for logstash

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}conf_d>0:${PORTSDIR}/textproc/py-conf_d \
	${PYTHON_PKGNAMEPREFIX}glob2>0:${PORTSDIR}/textproc/py-glob2 \
	${PYTHON_PKGNAMEPREFIX}msgpack>0:${PORTSDIR}/devel/py-msgpack \
	${PYTHON_PKGNAMEPREFIX}daemon>0:${PORTSDIR}/devel/py-daemon \
	${PYTHON_PKGNAMEPREFIX}redis>0:${PORTSDIR}/databases/py-redis \
	${PYTHON_PKGNAMEPREFIX}pyzmq>0:${PORTSDIR}/devel/py-pyzmq

# TODO
# - create mosquitto port
# - devel/py-pika
# - OPTIONS_DEFINE
.include <bsd.port.mk>
