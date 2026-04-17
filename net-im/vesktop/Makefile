PORTNAME=	vesktop
DISTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/Vencord/Vesktop/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}_${ARCH:S/aarch64/arm64/}
EXTRACT_SUFX=	.deb

MAINTAINER=	celeste@ornato.com
COMMENT=	Unofficial native 'improved' client for the discord messenger
WWW=		https://vesktop.dev/

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64 aarch64

USES=		electronfix:39
ELECTRONFIX_MAIN_EXECUTABLE=	vesktop

NO_BUILD=	yes

_ICON_DIR=	${PREFIX}/share/icons/hicolor/scalable/apps

do-extract:
	${MKDIR} ${EXTRACT_WRKDIR}/${DISTNAME}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} -O --include data.tar.xz | ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} - -C ${EXTRACT_WRKDIR}/${DISTNAME} ${EXTRACT_AFTER_ARGS}

pre-install:
	echo 'freebsd' > ${WRKSRC}/opt/Vesktop/resources/package-type

do-install:
	cd ${WRKSRC}/opt/Vesktop && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${_ICON_DIR}
	${INSTALL_DATA} ${WRKSRC}/usr/share/icons/hicolor/scalable/apps/vesktop.svg ${STAGEDIR}${_ICON_DIR}
	${RLN} ${STAGEDIR}${DATADIR}/vesktop ${STAGEDIR}${PREFIX}/bin/vesktop
	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/vesktop.desktop ${STAGEDIR}${PREFIX}/share/applications
	${REINPLACE_CMD} -e 's|Exec=.*|Exec=vesktop|' \
		${STAGEDIR}${PREFIX}/share/applications/vesktop.desktop

.include <bsd.port.mk>
