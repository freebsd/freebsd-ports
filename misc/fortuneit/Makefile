# New ports collection makefile for:   fortuneit
# Date created:        25-01-1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	fortuneit
PORTVERSION=	1.51
CATEGORIES=	misc
MASTER_SITES=	http://www.giovannelli.it/~gmarco/files/
DISTNAME=	fortune.it-${PORTVERSION}

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	A very funny fortune file in Italian

NO_BUILD=	yes

STRCMD=		/usr/games/strfile

.if defined(INSTALL_OFFENSIVE)
PLIST=		${PKGDIR}/pkg-plist.off
.endif

pre-fetch:
.if !defined(INSTALL_OFFENSIVE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to install potentially offensive italian"
	@${ECHO_MSG} "fortunes \"make INSTALL_OFFENSIVE=yes\""
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Potentially offensive fortunes will be installed"
	@${ECHO_MSG} ""
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/italia ${PREFIX}/share/games/fortune
.if defined(INSTALL_OFFENSIVE)
	@${INSTALL_DATA} ${WRKSRC}/zozzital ${PREFIX}/share/games/fortune
.endif

pre-install:
.if !exists(${STRCMD})
	@ ${ECHO_MSG}	"Please install the games distribution"
	@ exit 1
.endif

post-install:
	@${STRCMD} ${PREFIX}/share/games/fortune/italia
.if defined(INSTALL_OFFENSIVE)
	@${STRCMD} ${PREFIX}/share/games/fortune/zozzital
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/italia"
.if defined(INSTALL_OFFENSIVE)
	@${ECHO_MSG} "or"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/zozzital"
.endif
	@${ECHO_MSG} ""

.include <bsd.port.mk>
