# New ports collection makefile for:	colorls
# Version required:	FreeBSD-2.2-stable (around August '98)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $FreeBSD$
#

DISTNAME=	colorls-2.2.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	ls-2.2.7.tar.gz

MAINTAINER=	asami@FreeBSD.org

MAN1=		colorls.1
MANCOMPRESSED=	maybe

WRKSRC=		${WRKDIR}/ls

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.mk>
