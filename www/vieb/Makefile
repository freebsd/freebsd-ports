PORTNAME=	vieb
DISTVERSION=	10.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/Jelmerro/Vieb/releases/download/${PORTVERSION}/ \
		LOCAL/nivit/${PORTNAME}/:images
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-images-${PORTVERSION}${EXTRACT_SUFX}:images

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Vim Inspired Electron Browser
WWW=		https://vieb.dev

LICENSE=	GPLv3+

USES=		desktop-file-utils electronfix:25

NO_BUILD=	yes
SUB_FILES=	${PORTNAME}

ELECTRONFIX_MAIN_EXECUTABLE=	${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
.for size in 16 32 48 64 128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	cd ${WRKDIR}/${PORTNAME}-images-${PORTVERSION} && \
	${INSTALL_DATA} icons/${size}x${size}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	cd ${WRKDIR}/${PORTNAME}-images-${PORTVERSION} && \
	${INSTALL_DATA} ${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
