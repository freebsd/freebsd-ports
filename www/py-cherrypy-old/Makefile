# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	cherrypy
PORTVERSION=	2.3.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-old
DISTNAME=	CherryPy-${PORTVERSION:C/\.b$/beta/}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pythonic, object-oriented web development framework

LICENSE=	BSD3CLAUSE

USES=		python:2.7
USE_PYTHON=	autoplist distutils

PORTSCOUT=	ignore:1        # This the last version of 2.3.X branch

.include <bsd.port.mk>
