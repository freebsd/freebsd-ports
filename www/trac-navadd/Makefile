# $FreeBSD$

PORTNAME=	navadd
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for adding navigation items into Trac navigation bars

RUN_DEPENDS+=	tracd:www/trac

USES=		python:2
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/${PORTNAME}plugin

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
