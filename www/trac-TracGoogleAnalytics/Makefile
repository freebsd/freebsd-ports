# New ports collection makefile for:    trac-TracGoogleAnalytics
# Date created:                         14 October 2010
# Whom:                                 Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	TracGoogleAnalytics
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Trac plugin to enable logging by Google Analytics

BUILD_DEPENDS=	tracd:${PORTSDIR}/www/trac
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
