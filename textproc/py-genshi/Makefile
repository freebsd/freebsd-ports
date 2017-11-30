# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	Genshi
PORTVERSION=	0.7
PORTREVISION=	2
#PORTEPOCH=	0
CATEGORIES=	textproc www python
MASTER_SITES=	http://ftp.edgewall.com/pub/${PORTNAME:tl}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python toolkit for stream-based generation of output for the web

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	BABEL
BABEL_DESC=	I18n support through the Babel plugin

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBABEL}
RUN_DEPENDS+=	${PKGNAMEPREFIX}Babel>=0.9.6:devel/py-babel@${FLAVOR}
.endif

.include <bsd.port.mk>
