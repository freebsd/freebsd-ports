# New ports collection makefile for:	colorls
# Version required:	FreeBSD-2.2-stable (around October '97)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id: Makefile,v 1.13 1997/04/30 03:18:06 asami Exp $
#

DISTNAME=	colorls
PKGNAME=	colorls-2.2.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	ls-2.2.5.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/ls

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.mk>
