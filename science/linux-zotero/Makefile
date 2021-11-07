PORTNAME=	zotero
DISTVERSION=	5.0.96.3
CATEGORIES=	science deskutils linux
MASTER_SITES=	https://download.zotero.org/client/release/${DISTVERSION}/ \
		https://raw.githubusercontent.com/zotero/zotero-standalone-build/${DISTVERSION}/:LICENSE
PKGNAMEPREFIX=	linux-
DIST_SUBDIR=	${PORTNAME}
DISTFILES=	${_MAIN_DISTFILE} \
		COPYING:LICENSE
EXTRACT_ONLY=	${_MAIN_DISTFILE}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Reference management for bibliographic data and research materials

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKDIR}/COPYING

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils linux tar:bz2
WRKSRC=		${WRKDIR}/Zotero_linux-x86_64
USE_LINUX=	dbusglib gtk3

SUB_FILES=	zotero-wrapper

_BINARIES=	pdftotext pdfinfo zotero-bin
_MAIN_DISTFILE=	Zotero-${DISTVERSION}_linux-x86_64${EXTRACT_SUFX}

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/COPYING ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${BRANDELF} -t Linux ${_BINARIES})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${CHMOD} +x ${_BINARIES})
# Only strip zotero-bin. Other ${_BINARIES} break strip(1).
	(cd ${STAGEDIR}${DATADIR} && ${STRIP_CMD} zotero-bin)
	${MV} ${STAGEDIR}${DATADIR}/zotero.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/zotero-wrapper ${STAGEDIR}${PREFIX}/bin/zotero

.include <bsd.port.mk>
