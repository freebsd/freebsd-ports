# New ports collection makefile for:	traceroute
# Date created:		20 February 1997
# Whom:			chris@vader.org
#
# $FreeBSD$
#

PORTNAME=	traceroute
PORTVERSION=	${RELEASEDATE}	
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/	\
	  	http://www.chg.ru/~dima/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	demon@FreeBSD.org

RELEASEDATE=	991603
NO_WRKSUBDIR=	yes
MAN8=		traceroute.8

do-install:
	${INSTALL} -c -m 4755 -o root -g bin ${WRKSRC}/traceroute ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/traceroute.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
