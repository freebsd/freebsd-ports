# New ports collection makefile for:	divx.com player
# Date created:				Sun May 19 22:17:41 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	divxplayer
PORTVERSION=	0.2.0
CATEGORIES=	multimedia linux
MASTER_SITES=	http://download.divx.com/player/
PKGNAMEPREFIX=	linux-
DISTNAME=	divx-player-installer

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	DivX(TM) Video Player for Linux from DivX.com

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
USE_X_PREFIX=	yes
USE_SIZE=	yes
NO_BUILD=	yes
STRIP=
WRKSRC=		${WRKDIR}/divx-player-installer
STRIP_CMD=	${LINUXBASE}/usr/bin/strip

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

BINARY_NAME=	divxPlayer.bin

post-patch:
	@${SED} -e "s|%%DATADIR%%|${DATADIR}|" ${FILESDIR}/wrapper.sh \
		> ${WRKDIR}/wrapper.sh

do-install:
# skin files
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/Skins
	@${INSTALL_DATA} ${WRKSRC}/Skins/* ${DATADIR}/Skins
# player
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/${BINARY_NAME:S/.bin$//}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

.include <bsd.port.post.mk>
