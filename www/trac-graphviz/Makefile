# $FreeBSD$

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;S;Plugin$;;:tl}
PORTVERSION=	0.7.4
PORTREVISION=	7
CATEGORIES=	www devel graphics python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphviz plugin for Trac's wiki

LICENSE=	BSD3CLAUSE

RUN_DEPENDS+=	urwfonts>0:${PORTSDIR}/x11-fonts/urwfonts \
		dot:${PORTSDIR}/graphics/graphviz \
		tracd:${PORTSDIR}/www/trac

USES=		python:2
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	graphviz
WRKSRC=			${WRKDIR}/${PORTNAME}plugin

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    -e 's|%%PREFIX%%|${PREFIX}|' \
	    -e 's|%%OSMAJOR%%|${OSREL:C/\..*$//}|' \
	${WRKSRC}/graphviz/graphviz.py

.include <bsd.port.mk>
