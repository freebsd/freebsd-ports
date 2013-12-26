# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	wikinegotiator
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Content negotiation for Trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/trac${PORTNAME}plugin
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
