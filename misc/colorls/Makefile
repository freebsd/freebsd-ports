# New ports collection makefile for:	colorls
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $FreeBSD$
#

PORTNAME=	colorls
PORTVERSION=	3.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/colorls
DISTFILES=	ls-${PORTVERSION}.tar.gz

MAINTAINER=	asami@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500004 || ${OSVERSION} < 500000 && ${OSVERSION} >= 400020
FORBIDDEN=	"colour support is already in the base system"
.endif

MAN1=		colorls.1
MANCOMPRESSED=	maybe

WRKSRC=		${WRKDIR}/ls

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.post.mk>
