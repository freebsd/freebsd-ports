# New ports collection makefile for:	colorls
# Version required:	FreeBSD-current (around March '95)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id: Makefile,v 1.5 1995/04/23 13:02:01 asami Exp $
#

DISTNAME=	colorls
PKGNAME=	colorls-2.0.5
CATEGORIES+=	utilities
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/bin/
DISTFILES=	ls.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

FETCH_DEPENDS=	ncftp2:${PORTSDIR}/net/ncftp2

WRKSRC=		${WRKDIR}/pub/FreeBSD/FreeBSD-current/src/bin/ls
NCFTP=		ncftp2
NCFTPFLAGS=	

.include <bsd.port.mk>
