# New ports collection makefile for:	wmbiff
# Date created:			19 Nov 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmbiff
PORTVERSION=	0.3.3
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		wmbiff.1
MAN5=		wmbiffrc.5

post-install:
	@${ECHO} "===>   Installing sample.wmbiffrc to ${PREFIX}/share/wmbiff"
	@${ECHO} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	@${MKDIR} ${PREFIX}/share/wmbiff && ${CHMOD} a+rx ${PREFIX}/share/wmbiff
	@${INSTALL_DATA} ${WRKSRC}/sample.wmbiffrc ${PREFIX}/share/wmbiff
	@${CHMOD} 644 ${PREFIX}/share/wmbiff/sample.wmbiffrc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
