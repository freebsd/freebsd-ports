# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	selenium
PORTVERSION=	2.37.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python bindings for Selenium

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rdflib>=3.1.0:${PORTSDIR}/textproc/py-rdflib

LATEST_LINK=	py-${PORTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	FIREFOX
FIREFOX_DESC=	Install Firefox

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREFOX}
USE_FIREFOX=	yes
.endif

.include <bsd.port.mk>
