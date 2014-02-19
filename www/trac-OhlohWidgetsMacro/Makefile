# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	OhlohWidgetsMacro
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Trac macro to embed Ohloh widgets

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycerberus>=0.3:${PORTSDIR}/devel/py-pycerberus \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
