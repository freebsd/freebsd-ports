# Created by: chris@vader.org
# $FreeBSD$

PORTNAME=	traceroute
PORTVERSION=	${RELEASEDATE}	
CATEGORIES=	net
MASTER_SITES=	http://mitya.pp.ru/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Version of 'traceroute' that shows the AS network number of each hop

RELEASEDATE=	991603
NO_WRKSUBDIR=	yes
MAN8=		traceroute.8
PLIST_FILES=	sbin/traceroute

NO_STAGE=	yes
do-install:
	${INSTALL} -c -m 4755 -o root -g bin ${WRKSRC}/traceroute ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/traceroute.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
