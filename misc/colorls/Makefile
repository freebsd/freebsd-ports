# New ports collection makefile for:	colorls
# Version required:	FreeBSD-current (around October '95)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id: Makefile,v 1.8 1995/11/26 10:47:32 asami Exp $
#

DISTNAME=	colorls
PKGNAME=	colorls-2.1
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/bin/
DISTFILES=	ls.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/ls

pre-patch:
	cp ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include <bsd.port.mk>
