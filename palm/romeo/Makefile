# ex:ts=8
# New ports collection makefile for:	romeo
# Date created:			Mar 25, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	romeo
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	The Palm ROM Discombobulator

PLIST_FILES=	bin/romeo
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/romeo ${PREFIX}/bin

.include <bsd.port.post.mk>
