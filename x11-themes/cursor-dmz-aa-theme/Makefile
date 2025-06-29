PORTNAME=	cursor-dmz-aa-theme
DISTVERSION=	0.4.5.2
CATEGORIES=	x11-themes
MASTER_SITES=	DEBIAN/pool/main/d/dmz-cursor-theme
DISTNAME=	dmz-cursor-theme_${DISTVERSION}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	DMZ AA style neutral scalable cursor theme
WWW=		https://jimmac.eu

LICENSE=	CC-BY-SA-3.0

BUILD_DEPENDS=	xcursorgen:x11/xcursorgen

USES=		tar:xz
DATADIR=	${PREFIX}/share/icons/Vanilla-DMZ-AA
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}/DMZ-Black

do-build:
	(cd ${WRKSRC}/pngs && \
		${SH} make.sh)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} index.theme \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/cursors
	(cd ${WRKSRC}/xcursors && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/cursors)

.include <bsd.port.mk>
