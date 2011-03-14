# New ports collection makefile for:	wmq3
# Date created:				Sat Dec 29 23:19:57 EST 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmq3
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	net windowmaker games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that query and display information on Quake 3 servers

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_GMAKE=	yes
USE_XORG=	xpm

SUB_FILES=	pkg-message

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmq3 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/wmq3rc ${EXAMPLESDIR}

.include <bsd.port.mk>
