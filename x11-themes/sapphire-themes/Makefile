# New ports collection makefile for:	sapphire-themes
# Date created:		2000-09-04
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	sapphire-themes
PORTVERSION=	1.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://jpj.net/~trevor/${PORTNAME}/
EXTRACT_SUFX=	.tar

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	xli:${PORTSDIR}/graphics/xli \
		xloadimage:${PORTSDIR}/x11/xloadimage \
		sapphire:${PORTSDIR}/x11-wm/sapphire

USE_X_PREFIX=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${X11BASE}/share/sapphire/themes/backgrounds/
	${INSTALL_DATA} ${WRKDIR}/themes/backgrounds/* \
		${X11BASE}/share/sapphire/themes/backgrounds/
	${INSTALL_DATA} ${WRKDIR}/themes/*.theme \
		${X11BASE}/share/sapphire/themes/
	${INSTALL_DATA} ${WRKDIR}/menu/default ${X11BASE}/share/sapphire/menu/

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
