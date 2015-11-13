# $FreeBSD$

PORTNAME=	cursor-dmz-theme
PORTVERSION=	0.4.4
CATEGORIES=	x11-themes
MASTER_SITES=	DEBIAN/pool/main/d/dmz-cursor-theme
DISTNAME=	dmz-cursor-theme_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DMZ style neutral scalable cursor theme

LICENSE=	CCbySA3
LICENSE_NAME=	Creative Commons Attribution-ShareAlike 3.0 Unported
LICENSE_TEXT=	See http://creativecommons.org/licenses/by-sa/3.0/
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	xcursorgen:${PORTSDIR}/x11/xcursorgen

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}/DMZ-White
DATADIR=	${PREFIX}/lib/X11/icons/Vanilla-DMZ

do-build:
	(cd ${WRKSRC}/pngs && ${SH} make.sh)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} index.theme \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/cursors
	(cd ${WRKSRC}/xcursors && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/cursors)

.include <bsd.port.mk>
