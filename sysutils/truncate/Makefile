# New ports collection makefile for:	truncate
# Date created:				27 Jun 2000
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	truncate
PORTVERSION=	3.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://big.endian.de/pub/FreeBSD/

MAINTAINER=	alex@FreeBSD.org

MAN1=		truncate.1
MANCOMPRESSED=	yes

MAKE_ENV+=	MANDIR=${PREFIX}/man/man BINDIR=${PREFIX}/bin
WRKSRC=		${WRKDIR}/truncate

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500011
BROKEN=		"truncate(1) is in the base-system"
.endif
.include <bsd.port.post.mk>
