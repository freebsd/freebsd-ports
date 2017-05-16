# $FreeBSD$

PORTNAME=	navadd
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Plugin for adding navigation items into Trac navigation bars

RUN_DEPENDS=	tracd:www/trac

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}plugin

.include <bsd.port.mk>
