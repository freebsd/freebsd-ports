# New ports collection makefile for:	wmtz
# Date created:			24 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmtz
PORTVERSION=	0.5
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.algonet.se/~jlin/wmtz/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmtz
USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
	@${ECHO} "===>   Installing wmtzrc in ${PREFIX}/share/examples/wmtz"
	@${ECHO} "===>   Modify to your config and copy to ~/.wmtzrc"
	@${MKDIR} ${PREFIX}/share/examples/wmtz && ${CHMOD} a+rx ${PREFIX}/share/examples/wmtz
	@${INSTALL_DATA} ${WRKSRC}/wmtzrc ${PREFIX}/share/examples/wmtz
	@${ECHO} "===>   Run wmtz --help for usage instructions"

.include <bsd.port.mk>
