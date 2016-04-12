# Created by: glarkin
# $FreeBSD$

PORTNAME=	ccselector
PORTVERSION=	0.0.2.4001
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visually edit the Trac ticket CC field

RUN_DEPENDS+=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
