# New ports collection makefile for:	wmpop3
# Date created:			28 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpop3
PORTVERSION= 	0.5.6a
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://www.cs.mun.ca/~scotth/download/
DISTNAME=	WMPop3-${PORTVERSION}

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}/wmpop3
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

pre-build:
	(cd ${WRKSRC} && ${GMAKE} clean)

post-install:
	@${ECHO} "===>   Installing wmpop3rc in ${PREFIX}/share/examples/wmpop3"
	@${ECHO} "===>   Modify to your config and copy to ~/.wmpop3rc"
	@${MKDIR} ${PREFIX}/share/examples/wmpop3 && ${CHMOD} a+rx ${PREFIX}/share/examples/wmpop3
	@${INSTALL_DATA} ${WRKSRC}/wmpop3rc ${PREFIX}/share/examples/wmpop3
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/wmpop3"
	@${ECHO} "===>   Please read it for usage instructions"
	@${MKDIR} ${PREFIX}/share/doc/wmpop3 && ${CHMOD} a+rx ${PREFIX}/share/doc/wmpop3
	@${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/README ${PREFIX}/share/doc/wmpop3

.include <bsd.port.post.mk>
