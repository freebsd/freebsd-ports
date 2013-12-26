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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visually edit the Trac ticket CC field

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
