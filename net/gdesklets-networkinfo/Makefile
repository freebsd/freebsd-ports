# New ports collection makefile for:	gdesklets-networkinfo
# Date created:				06 January 2004
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	networkinfo
PORTVERSION=	0.8
CATEGORIES=	net gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	netload

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network load display for gdesklets system

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets \
		${X11BASE}/share/gnome/gdesklets/Sensors/Network/__init__.py:${PORTSDIR}/net/gdesklets-sensor-psi_network

USE_X_PREFIX=	yes

DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${PORTNAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}/gdesklets/Displays/${PORTNAME}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
