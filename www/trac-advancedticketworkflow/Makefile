# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	advancedticketworkflow
PORTVERSION=	0.10.3940
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://people.freebsd.org/~mm/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Advanced Ticket Workflow Plugin for Trac

RUN_DEPENDS=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
