# New ports collection makefile for:	wmcp
# Date created:			10 February 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmcp
PORTVERSION=	1.2.8
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://users.linuxbox.com/~bac/src/wmcp/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

pre-build:
	(cd ${WRKSRC} && ${GMAKE} clean)

do-build:
	(cd ${WRKSRC} && ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcp ${PREFIX}/bin

.include <bsd.port.mk>
