# New ports collection makefile for:	chimera
# Date created:		26 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	chimera
PORTVERSION=	1.70p0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.rocklinux.net/people/ripclaw/projects/software/chimera/devel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X/Athena World-Wide Web client

NO_LATEST_LINK=	yes
USE_IMAKE=	yes

MAN1=		chimera.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
