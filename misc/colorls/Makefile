# New ports collection makefile for:	colorls
# Version required:	FreeBSD-2.2-stable (around August '98)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $FreeBSD$
#

PORTNAME=	colorls
PORTVERSION=	2.2.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	ls-${PORTVERSION}.tar.gz

MAINTAINER=	asami@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500004
FORBIDDEN=      "colour support is already in the base system"
.endif

MAN1=		colorls.1
MANCOMPRESSED=	maybe

WRKSRC=		${WRKDIR}/ls

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.post.mk>
