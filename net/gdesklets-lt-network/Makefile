# New ports collection makefile for:	gdesklets-lt-network
# Date created:				20 March 2004
# Whom:					Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	lt-network
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-

MAINTAINER=	tim@bishnet.net
COMMENT=	An LTCandy compatible networkinfo display

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${X11BASE}/share/gnome/gdesklets/Sensors/Network/__init__.py:${PORTSDIR}/net/gdesklets-sensor-psi_network \
		${X11BASE}/share/gnome/gdesklets/Sensors/LTVBorder/__init__.py:${PORTSDIR}/deskutils/gdesklets-ltvariations

USE_X_PREFIX=	yes

DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${PORTNAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/bg
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/gfx/bg/*.png ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/bg/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
