# New ports collection makefile for:	colorls
# Version required:	FreeBSD-current (around January '97)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id: Makefile,v 1.12 1997/01/02 06:29:44 asami Exp $
#

DISTNAME=	colorls
PKGNAME=	colorls-2.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	ls.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/ls

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.mk>
