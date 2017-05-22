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

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Visually edit the Trac ticket CC field

RUN_DEPENDS=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USES=		python:2 zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
