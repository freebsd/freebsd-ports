# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kombu
PORTVERSION=	2.5.13
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	AMQP messaging framework for Python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqp>=1.0.13:${PORTSDIR}/net/py-amqp \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.3:${PORTSDIR}/devel/py-anyjson

OPTIONS_DEFINE=	BEANSTALK BOTO MONGODB REDIS SQLALCHEMY ZMQ

BEANSTALK_DESC=	Include beanstalkd transport support
BOTO_DESC=	Include AWS transport support
MONGODB_DESC=	Include MongoDB transport support
REDIS_DESC=	Include Redis transport support
SQLALCHEMY_DESC=Include SQLAlchemy transport support
ZMQ_DESC=	Include ZMQ transport support

# Ports infrastructure bug
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBEANSTALK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}beanstalkc>0:${PORTSDIR}/net/py-beanstalkc
.endif

.if ${PORT_OPTIONS:MBOTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}boto=>2.6.0:${PORTSDIR}/devel/py-boto
.endif

.if ${PORT_OPTIONS:MMONGODB}
RUN_DEPENDS+=	pymongo>0:${PORTSDIR}/databases/pymongo
.endif

.if ${PORT_OPTIONS:MREDIS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}redis>0:${PORTSDIR}/databases/py-redis
.endif

.if ${PORT_OPTIONS:MSQLALCHEMY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy
.endif

.if ${PORT_OPTIONS:MZMQ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyzmq=>2.2.0:${PORTSDIR}/devel/py-pyzmq
.endif

.if ${PYTHON_REL} < 270
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ordereddict>=0:${PORTSDIR}/devel/py-ordereddict \
		${PYTHON_PKGNAMEPREFIX}importlib>=0:${PORTSDIR}/devel/py-importlib
.endif

.include <bsd.port.post.mk>
