# $FreeBSD$

PORTNAME=	cursor-dmz-theme
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	DEBIAN/pool/main/d/dmz-cursor-theme
DISTNAME=	dmz-cursor-theme_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DMZ style neutral scalable cursor theme

LICENSE=	CC-BY-SA-3.0

BUILD_DEPENDS=	xcursorgen:x11/xcursorgen

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}/DMZ-White
DATADIR=	${PREFIX}/share/icons/Vanilla-DMZ

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
