# New ports collection makefile for:	sapphire-themes
# Date created:		2000-09-04
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	sapphire-themes
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-themes x11-wm
MASTER_SITES=	http://jpj.net/~trevor/${PORTNAME}/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for sapphire

RUN_DEPENDS=	xli:${PORTSDIR}/graphics/xli \
		xloadimage:${PORTSDIR}/x11/xloadimage \
		sapphire:${PORTSDIR}/x11-wm/sapphire

REINPLACE_ARGS=	-i '' -E
USE_X_PREFIX=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-patch:
	${REINPLACE_CMD} 's:~/\.:${X11BASE}/share/:g' \
		${WRKDIR}/menu/default \
		${WRKDIR}/themes/*.theme
	${REINPLACE_CMD} 's:-15-:-12-:g' ${WRKDIR}/themes/*.theme

do-install:
	${MKDIR} ${X11BASE}/share/sapphire/themes/backgrounds/
	${INSTALL_DATA} ${WRKDIR}/themes/backgrounds/* \
		${X11BASE}/share/sapphire/themes/backgrounds/
	${INSTALL_DATA} ${WRKDIR}/themes/*.theme \
		${X11BASE}/share/sapphire/themes/
	${INSTALL_DATA} ${WRKDIR}/menu/default ${X11BASE}/share/sapphire/menu/

.include <bsd.port.mk>
