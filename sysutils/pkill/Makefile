# New ports collection makefile for:	NetBSD's pgrep/pkill
# Date created:				Tue Nov 5 14:01:47 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkill
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	NetBSD's pgrep and pkill: find or signal processes matching criteria

MAKE_ENV=	DESTDIR=${PREFIX} \
		BINDIR=/bin \
		MANDIR=/man/man

MANCOMPRESSED=	yes
MAN1=		pgrep.1 pkill.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502110
IGNORE=		"is included in the base system"
.endif

.if ${OSVERSION} >= 500000
DISTNAME=	${PORTNAME}-current-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-current
.else
. if ${OSVERSION} <= 300000
MAKE_ENV+=	NEED_KMEM=1
. endif
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-stable
.endif

post-install:
.if ${OSVERSION} <= 300000
	@${CHGRP} kmem ${PREFIX}/bin/pkill 
	@${CHMOD} 2555 ${PREFIX}/bin/pkill
.endif

.include <bsd.port.post.mk>
