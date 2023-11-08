PORTNAME=	logseq
PORTVERSION=	0.9.20
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/logseq/logseq/releases/download/${PORTVERSION}/ \
		LOCAL/arrowd/:rsapi
DISTFILES=	Logseq-linux-x64-${PORTVERSION}${EXTRACT_SUFX} \
		logseq/rsapi.freebsd-x64.node${EXTRACT_SUFX}:rsapi

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Open-source platform for knowledge management and collaboration
WWW=		https://logseq.com

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils electronfix:25 shared-mime-info zip

ELECTRONFIX_MAIN_EXECUTABLE=	Logseq
SUB_FILES=	Logseq
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Logseq-linux-x64

post-patch:
	${RM} ${WRKSRC}/resources/app/node_modules/@logseq/rsapi-linux-x64-gnu/package.json.orig

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/Logseq ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/Logseq.desktop ${STAGEDIR}${DESKTOPDIR}/Logseq.desktop
	${INSTALL_DATA} ${WRKSRC}/resources/app/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/Logseq.png
	${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	${MV} ${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-linux-x64-gnu \
		${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-freebsd-x64
	${INSTALL_PROGRAM} ${WRKDIR}/rsapi.freebsd-x64.node ${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-freebsd-x64

.include <bsd.port.mk>
