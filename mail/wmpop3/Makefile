# New ports collection makefile for:	wmpop3
# Date created:			28 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpop3
PORTVERSION=	0.5.6a
PORTREVISION=	2
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://www.cs.mun.ca/~scotth/download/
DISTFILES=	WMPop3-${PORTVERSION}.tar.gz

MAINTAINER=	jim@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/wmpop3

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpop3 ${PREFIX}/bin
	@${ECHO} "===>   Installing wmpop3rc in ${PREFIX}/share/examples/wmpop3"
	@${ECHO} "===>   Modify to your config and copy to ~/.wmpop3rc"
	@${MKDIR} ${PREFIX}/share/examples/wmpop3
	${INSTALL_DATA} ${WRKSRC}/wmpop3rc ${PREFIX}/share/examples/wmpop3
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/wmpop3"
	@${ECHO} "===>   Please read it for usage instructions"
	@${MKDIR} ${PREFIX}/share/doc/wmpop3
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/README ${PREFIX}/share/doc/wmpop3
.endif

.include <bsd.port.mk>
