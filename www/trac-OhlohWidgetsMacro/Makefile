# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	OhlohWidgetsMacro
PORTVERSION=	0.2
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Trac macro to embed Ohloh widgets

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycerberus>=0.3:${PORTSDIR}/devel/py-pycerberus \
		tracd:${PORTSDIR}/www/trac

LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
