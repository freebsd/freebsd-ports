# New ports collection makefile for:	colorls
# Version required:	FreeBSD-current (around October '95)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id: Makefile,v 1.10 1996/11/11 05:49:20 obrien Exp $
#

DISTNAME=	colorls
PKGNAME=	colorls-2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/bin/
DISTFILES=	ls.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/ls
IGNOREFILES=	${DISTFILES}

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.mk>
