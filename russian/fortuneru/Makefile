# New ports collection makefile for:   fortuneru
# Date created:        26-09-2001
# Whom:                bestia@iptcom.net
#
# $FreeBSD$
#

PORTNAME=	fortuneru
PORTVERSION=	0.1
CATEGORIES=	russian
MASTER_SITES=	ftp://de22.kiev.ua/pub/files/
DISTNAME=	fortune.ru-${PORTVERSION}

MAINTAINER=	bestia@iptcom.net

NO_BUILD=	yes

STRCMD=		/usr/games/strfile

do-install:
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/speed-info ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/fomenko ${PREFIX}/share/games/fortune

pre-install:
.if !exists(${STRCMD})
	@ ${ECHO_MSG}	"Please install the games distribution"
	@ exit 1
.endif

post-install:
	@${STRCMD} ${PREFIX}/share/games/fortune/speed-info
	@${STRCMD} ${PREFIX}/share/games/fortune/fomenko
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/speed-info"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
