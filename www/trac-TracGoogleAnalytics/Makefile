# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	TracGoogleAnalytics
PORTVERSION=	0.2.4
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Trac plugin to enable logging by Google Analytics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tracd:www/trac \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:textproc/py-genshi@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
