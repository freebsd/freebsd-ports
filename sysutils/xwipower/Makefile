# New ports collection makefile for:	xwipower
# Date created:         05 July 2000
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	xwipower
PORTVERSION=	20000623
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fumi.org/pub/xwipower/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Wave power level meter for wi(4)

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/xwipower
USE_IMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
