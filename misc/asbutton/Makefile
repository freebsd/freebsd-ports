# New ports collection makefile for:	asbutton
# Version required:		0.2
# Date created:			10 May 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	asbutton-0.2
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/as-apps/download/asbutton/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

do-build:
	(cd ${WRKSRC} && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asbutton ${PREFIX}/bin
	@${ECHO} "		"
	@${ECHO} "===> Installing icons in ${PREFIX}/share/asbutton"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/asbutton && chmod a+rx ${PREFIX}/share/asbutton
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/share/asbutton

post-install:
	@${ECHO} "		"
	@${ECHO} "===> Installing  sample asbuttonrc in ${PREFIX}/share/examples/asbutton"
	@${ECHO} "===> Copy to ~/.asbuttonrc and modify to desired config."
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/examples/asbutton && chmod a+rx ${PREFIX}/share/examples/asbutton
	${INSTALL_DATA} ${WRKSRC}/.asbuttonrc ${PREFIX}/share/examples/asbutton/asbuttonrc && chmod u+rw ${PREFIX}/share/examples/asbutton/asbuttonrc
	@${ECHO} "		"
	@${ECHO} "===> Use 'asbutton -h' for help."

.include <bsd.port.mk>
