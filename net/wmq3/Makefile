# New ports collection makefile for:	wmq3
# Date created:				Sat Dec 29 23:19:57 EST 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmq3
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	net windowmaker games
MASTER_SITES=	http://www.soberart.de/down/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Dockapp that query and display information on Quake 3 servers

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmq3 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/wmq3rc \
		${PREFIX}/share/examples/${PORTNAME}

post-install:
	@${SED} 's|%%EXAMPLEDIR%%|${PREFIX}/share/examples/${PORTNAME}|' \
		${PKGMESSAGE}

.include <bsd.port.mk>
