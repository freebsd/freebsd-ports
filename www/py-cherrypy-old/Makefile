# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	cherrypy
PORTVERSION=	2.3.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-old
DISTNAME=	CherryPy-${PORTVERSION:C/\.b$/beta/}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Pythonic, object-oriented web development framework

LICENSE=	BSD3CLAUSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTSCOUT=	ignore:1        # This the last version of 2.3.X branch

.include <bsd.port.mk>
