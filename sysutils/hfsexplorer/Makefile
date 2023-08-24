PORTNAME=	hfsexplorer
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2021.10.9
CATEGORIES=	sysutils java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HFSExplorer read Mac-formatted harddisks and disk images
WWW=		https://www.catacombae.org/hfsexplorer/

LICENSE=	GPLv3

BUILD_DEPENDS=	ant:devel/apache-ant

USE_GITHUB=	yes
GH_ACCOUNT=	unsound
USE_JAVA=	yes

DESKTOP_ENTRIES=	"hfsexplorer" \
			"reader Mac-formatted harddisk" \
			"${DATADIR}/res/icon.png" \
			"${PORTNAME}" \
			"System;Utility;Java;" \
			false

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-configure:
	@cd ${WRKSRC}/dist/bin && ${REINPLACE_CMD} -e 's|BASEDIR=".*"|BASEDIR="${DATADIR}/lib"|g' \
		hfsx resview unhfs
	@${REINPLACE_CMD} -e 's|BASEDIR=".*"|BASEDIR="${DATADIR}/lib"|g' \
		${WRKSRC}/dist/bin/hfsexplorer

do-build:
	@cd ${WRKSRC} && ${SH} buildall

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/res
.for f in hfsx resview unhfs
	cd ${WRKSRC} && ${INSTALL_SCRIPT} dist/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	cd ${WRKSRC} && ${INSTALL_SCRIPT} dist/bin/hfsexplorer ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} dist/lib/*.jar ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC} && ${INSTALL_DATA} dist/res/icon.png ${STAGEDIR}${DATADIR}/res

do-install-DOCS-on:
	cd ${WRKSRC}/dist/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
