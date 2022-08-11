PORTNAME=	zotero
DISTVERSION=	6.0.10
PORTREVISION=	2
CATEGORIES=	science deskutils linux
MASTER_SITES=	https://download.zotero.org/client/release/${DISTVERSION}/ \
		https://raw.githubusercontent.com/zotero/zotero-standalone-build/${DISTVERSION}/:LICENSE
PKGNAMEPREFIX=	linux-
DISTFILES=	${_MAIN_DISTFILE} \
		COPYING:LICENSE
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${_MAIN_DISTFILE}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Reference management for bibliographic data and research materials

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKDIR}/COPYING

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils linux tar:bz2
USE_LINUX=	dbusglib gtk3

NO_BUILD=	yes

SUB_FILES=	zotero-wrapper

WRKSRC=		${WRKDIR}/Zotero_linux-x86_64

_BINARIES=	pdftotext pdfinfo zotero-bin
_ICONSDIR=	${PREFIX}/share/icons/hicolor
_ICON_SIZES=	16 32 48 256
_MAIN_DISTFILE=	Zotero-${DISTVERSION}_linux-x86_64${EXTRACT_SUFX}

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/COPYING ${WRKDIR}

do-configure:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${PORTNAME}.desktop
	(cd ${WRKSRC} && ${BRANDELF} -t Linux ${_BINARIES})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "! -name '*.orig' ! -name '*.bak'")
	(cd ${WRKSRC} && ${CHMOD} +x ${_BINARIES})
# Only strip zotero-bin. Other ${_BINARIES} break strip(1).
	(cd ${STAGEDIR}${DATADIR} && ${STRIP_CMD} zotero-bin)
	${MV} ${STAGEDIR}${DATADIR}/zotero.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/zotero-wrapper ${STAGEDIR}${PREFIX}/bin/zotero
.for _size in ${_ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${_ICONSDIR}/${_size}x${_size}/apps
	${RLN} ${STAGEDIR}${DATADIR}/chrome/icons/default/default${_size}.png \
		${STAGEDIR}${_ICONSDIR}/${_size}x${_size}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
