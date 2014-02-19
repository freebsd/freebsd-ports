# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	Genshi
PORTVERSION=	0.7
PORTREVISION=	1
#PORTEPOCH=	0
CATEGORIES=	textproc www python
MASTER_SITES=	http://ftp.edgewall.com/pub/${PORTNAME:L}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python toolkit for stream-based generation of output for the web

LICENSE=	BSD

OPTIONS_DEFINE=	BABEL
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options
BABEL_DESC=	I18n support through the Babel plugin

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBABEL}
RUN_DEPENDS+=	${PKGNAMEPREFIX}Babel>=0.9.6:${PORTSDIR}/devel/py-babel
.endif

.include <bsd.port.mk>
