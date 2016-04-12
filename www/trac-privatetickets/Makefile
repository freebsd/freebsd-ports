# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	privatetickets
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	trac-
DISTNAME=	TracPrivateTickets-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Modified ticket security for Trac

RUN_DEPENDS=	tracd:www/trac

USES=		python
USE_PYTHON=	distutils autoplist

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
