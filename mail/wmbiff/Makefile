# New ports collection makefile for:	wmbiff
# Date created:			19 Nov 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmbiff
PORTVERSION=	0.2
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	http://ccat.elect.ru:8100/wmbiff/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff
USE_X_PREFIX=	yes
USE_XPM=	yes

pre-build:
	@(cd ${WRKSRC} && ${GMAKE} clean)

post-install:
	@${ECHO} "===>   Installing sample.wmbiffrc to ${PREFIX}/share/examples/wmbiff"
	@${ECHO} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	@${MKDIR} ${PREFIX}/share/examples/wmbiff && ${CHMOD} a+rx ${PREFIX}/share/examples/wmbiff
	@${INSTALL_DATA} ${WRKSRC}/sample.wmbiffrc ${PREFIX}/share/examples/wmbiff
	@${CHMOD} 644 ${PREFIX}/share/examples/wmbiff/sample.wmbiffrc

.include <bsd.port.mk>
