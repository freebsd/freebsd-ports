# New ports collection makefile for:	gdesklets-ebichuclock
# Date created:				07 January 2004
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	ebichuclock
PORTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very simple clock with a small Ebichu picture in it

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${X11BASE}/share/gnome/gdesklets/Sensors/Clock/__init__.py:${PORTSDIR}/x11-clocks/gdesklets-clock

USE_BZIP2=	yes
USE_X_PREFIX=	yes

NAME=		ebichuclock
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
