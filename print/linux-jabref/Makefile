PORTNAME=	jabref
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3
PORTEPOCH=	1
CATEGORIES=	print education java editors linux
MASTER_SITES=	https://github.com/JabRef/jabref/releases/download/v${DISTVERSION}/ \
		https://raw.githubusercontent.com/JabRef/jabref/v${DISTVERSION}/snap/gui/:_desktop \
		https://github.com/JabRef/jabref/raw/v${DISTVERSION}/snap/gui/:icon
PKGNAMEPREFIX=	linux-
DISTFILES=	${_MAIN_DISTFILE} \
		${_DESKTOP_FILE}:_desktop \
		${_ICON_FILE}:icon
EXTRACT_ONLY=	${_MAIN_DISTFILE}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	BibTeX native bibliographic reference manager (Linux version)

LICENSE=	BSD2CLAUSE GPLv2 GPLv3
LICENSE_COMB=	multi

USES=		cpe desktop-file-utils linux
USE_LINUX=	gtk3 libglvnd

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/JabRef

SUB_FILES=	${PORTNAME}-wrapper

_DESKTOP_FILE=	${PORTNAME}.desktop
_ICON_FILE=	${PORTNAME}.png
_MAIN_DISTFILE=	JabRef-${DISTVERSION}-portable_linux${EXTRACT_SUFX}
_ICON_PATH=	${PREFIX}/share/pixmaps/${_ICON_FILE}

post-extract:
	@${CP} ${DISTDIR}/${_DESKTOP_FILE} ${WRKDIR}
	@${CP} ${DISTDIR}/${_ICON_FILE} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} 's|^Icon=.*|Icon=${_ICON_PATH}|g' ${WRKDIR}/${_DESKTOP_FILE}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${CHMOD} +x ${STAGEDIR}${DATADIR}/bin/*

	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${_DESKTOP_FILE} ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${_ICON_PATH:H}
	${INSTALL_DATA} ${WRKDIR}/${_ICON_FILE} ${STAGEDIR}${_ICON_PATH}

.include <bsd.port.mk>
