# New ports collection makefile for:	wmtz
# Version required:		0.2
# Date created:			24 Apr 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	wmtz-0.2
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.algonet.se/~jlin/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmtz
USE_X_PREFIX=	yes

post-install:
	@${ECHO} "		"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "===> Installing wmtzrc in ${PREFIX}/share/examples/wmtz"
	@${ECHO} "===> Modify to your config and copy to ~/.wmtzrc"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/examples/wmtz && chmod a+rx ${PREFIX}/share/examples/wmtz
	${INSTALL_DATA} ${WRKSRC}/wmtzrc ${PREFIX}/share/examples/wmtz
	@${ECHO} "		"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "===> Run wmtz --help for usage instructions"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "		"

.include <bsd.port.mk>
