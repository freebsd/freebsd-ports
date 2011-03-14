# New ports collection makefile for:	slurp
# Date created:		30 Jun 1996
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	slurp
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/news/slurp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passive NNTP client to retrieve Usenet articles from a remote server

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes
MAN1=		slurp.1

pre-install:
	${MKDIR} ${PREFIX}/news/lib ${PREFIX}/news/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurp ${PREFIX}/news/bin
	${INSTALL_MAN} ${WRKSRC}/slurp.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/slurp.sys ${PREFIX}/news/lib/slurp.sys.sample

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
