# New ports collection makefile for:	xwipower
# Date created:         05 July 2000
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	xwipower
PORTVERSION=	20000623
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fumi.org/pub/xwipower/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Wave power level meter for wi(4)

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/xwipower
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt xpm

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700053
BROKEN=		Use obsoleted wireless lan API
.endif

.include <bsd.port.post.mk>
