# New ports collection makefile for:	wmtz
# Version required:		0.4
# Date created:			24 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wmtz-0.4
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.algonet.se/~jlin/wmtz/ \
		http://www.freebsd.org/~jim/distfiles/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmtz
USE_X_PREFIX=	yes

post-install:
	@${ECHO} "===>   Installing wmtzrc in ${PREFIX}/share/examples/wmtz"
	@${ECHO} "===>   Modify to your config and copy to ~/.wmtzrc"
	@${MKDIR} ${PREFIX}/share/examples/wmtz && ${CHMOD} a+rx ${PREFIX}/share/examples/wmtz
	@${INSTALL_DATA} ${WRKSRC}/wmtzrc ${PREFIX}/share/examples/wmtz
	@${ECHO} "===>   Run wmtz --help for usage instructions"

.include <bsd.port.mk>
