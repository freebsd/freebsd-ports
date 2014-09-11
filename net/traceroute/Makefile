# Created by: chris@vader.org
# $FreeBSD$

PORTNAME=	traceroute
PORTVERSION=	${RELEASEDATE}
CATEGORIES=	net
MASTER_SITES=	http://mitya.pp.ru/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Version of 'traceroute' that shows the AS network number of each hop

RELEASEDATE=	991603
NO_WRKSUBDIR=	yes
PLIST_FILES=	"@(,,4555) sbin/traceroute" man/man8/traceroute.8.gz
USES=		tar:Z

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/traceroute \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/traceroute.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
