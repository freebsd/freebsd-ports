# New ports collection makefile for:	traceroute
# Version required:	980831
# Date created:		20 February 1997
# Whom:			chris@vader.org
#
# $Id: Makefile,v 1.2 1998/12/04 21:53:42 billf Exp $
#

DISTNAME=	traceroute_${RELEASEDATE}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/	\
	  	http://www.chg.ru/~dima/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dima@Chg.RU

RELEASEDATE=	990207
NO_WRKSUBDIR=	yes
MAN8=		traceroute.8

do-install:

	${INSTALL} -m 4755 -o root -g bin ${WRKSRC}/traceroute ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/traceroute.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
