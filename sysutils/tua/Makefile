# New ports collection makefile for:	tua
# Date created:		11 Feb. 1995
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	tua
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.vmunix.org/pub/misc/tua/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Uucp Analyzer

GNU_CONFIGURE=	yes
MAN1=		tua.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

.include <bsd.port.post.mk>
