# New ports collection makefile for:	colorls
# Version required:	FreeBSD-current (around October '95)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id: Makefile,v 1.9 1996/03/06 23:08:43 asami Exp $
#

DISTNAME=	colorls
PKGNAME=	colorls-2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/bin/
DISTFILES=	ls.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/ls

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.mk>
