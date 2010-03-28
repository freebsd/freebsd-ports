# New ports collection makefile for:	gdesklets-ebichuclock
# Date created:				07 January 2004
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	ebichuclock
PORTVERSION=	0.1.1
PORTREVISION=	13
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://www.gdesklets.info/archive/
PKGNAMEPREFIX=	gdesklets-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very simple clock with a small Ebichu picture in it

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${LOCALBASE}/share/gdesklets/Sensors/Clock/__init__.py:${PORTSDIR}/x11-clocks/gdesklets-clock

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PYTHON=	yes

SUB_FILES=	pkg-message
SUB_LIST=	NAME="${NAME}"

DATADIR=	${PREFIX}/share/gdesklets
NAME=		ebichuclock

do-install:
	@${MKDIR} ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}
	@${MKDIR} ${DATADIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/Displays/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
