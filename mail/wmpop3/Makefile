# New ports collection makefile for:	wmpop3
# Version required:		0.5.0a
# Date created:			28 Mar 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.2 1999/06/19 23:32:45 cpiazza Exp $
#

DISTNAME=	WMPop3-0.5.5a
PKGNAME=	wmpop3-0.5.5a
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://www.cs.mun.ca/~scotth/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}/wmpop3
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

pre-build:
	(cd ${WRKSRC} && ${GMAKE} clean)

post-install:
	@${ECHO} "		"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "===> Installing wmpop3rc in ${PREFIX}/share/examples/wmpop3"
	@${ECHO} "===> Modify to your config and copy to ~/.wmpop3rc"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/examples/wmpop3 && chmod a+rx ${PREFIX}/share/examples/wmpop3
	${INSTALL_DATA} ${WRKSRC}/wmpop3rc ${PREFIX}/share/examples/wmpop3
	@${ECHO} "		"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "===> Installing README in ${PREFIX}/share/doc/wmpop3"
	@${ECHO} "===> Please read it for usage instructions"
	@${ECHO} "-----------------------------------------------------------"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/doc/wmpop3 && chmod a+rx ${PREFIX}/share/doc/wmpop3
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/README ${PREFIX}/share/doc/wmpop3

.include <bsd.port.mk>
