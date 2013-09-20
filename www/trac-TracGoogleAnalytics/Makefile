# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	TracGoogleAnalytics
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Trac plugin to enable logging by Google Analytics

BUILD_DEPENDS=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:${PORTSDIR}/textproc/py-genshi

RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	BSD

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
