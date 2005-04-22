# New ports collection makefile for:   tolkien-ttf
# Date created:				24 February 2005
# Whom:					Andrea Franchi <obscure9@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tolkien-ttf
PORTVERSION=	0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.northernstorm.org/distfiles/

MAINTAINER=	obscure9@gmail.com
COMMENT=	A selection of the best TrueType fonts for JRR Tolkien Languages

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

RESTRICTED=	"Shareware. Unlicensed commercial usage/redistribution prohibited."

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes
FONTSDIR=	lib/X11/fonts/${PORTNAME}/
PLIST_SUB+=	FONTSDIR=${FONTSDIR}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.TTF ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.cache-1 ${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_MSG} "==> Running fc-cache"
	@${X11BASE}/bin/fc-cache -f -v ${PREFIX}/${FONTSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
