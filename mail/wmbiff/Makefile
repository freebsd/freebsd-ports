# New ports collection makefile for:	wmbiff
# Version required:		0.1a
# Date created:			19 Nov 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wmbiff-0.1a
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	http://ccat.elect.ru:8100/wmbiff/ \
		http://www.freebsd.org/~jim/distfiles/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff
USE_X_PREFIX=	yes

pre-build:
	@(cd ${WRKSRC} && ${GMAKE} clean)

post-install:
	@${ECHO} "===>   Installing sample.wmbiffrc to ${PREFIX}/share/examples/wmbiff"
	@${ECHO} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	@${MKDIR} ${PREFIX}/share/examples/wmbiff && ${CHMOD} a+rx ${PREFIX}/share/examples/wmbiff
	@${INSTALL_DATA} ${WRKSRC}/sample.wmbiffrc ${PREFIX}/share/examples/wmbiff
	@${CHMOD} 644 ${PREFIX}/share/examples/wmbiff/sample.wmbiffrc

.include <bsd.port.mk>
