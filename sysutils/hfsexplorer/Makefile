# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hfsexplorer
PORTVERSION=	0.23
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	sysutils java

MAINTAINER=	vg@FreeBSD.org
COMMENT=	HFSExplorer read Mac-formatted harddisks and disk images

LICENSE=	GPLv3

BUILD_DEPENDS=	ant:devel/apache-ant

DESKTOP_ENTRIES="hfsexplorer" "reader Mac-formatted harddisk" \
		"${DATADIR}/res/icon.png" "${PORTNAME}" \
		"System;Utility;Java;" false

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}
GH_ACCOUNT=	unsound

USE_JAVA=	yes
JAVA_VERSION=	1.6+
OPTIONS_DEFINE= DOCS
NO_ARCH=	yes

do-configure:
	@cd ${WRKSRC}/dist/bin && ${REINPLACE_CMD} -e 's|BASEDIR=".*"|BASEDIR="${DATADIR}/lib"|g' \
		hfsx.sh resview.sh unhfs.sh
	@${REINPLACE_CMD} -e 's|BASEDIR=".*"|BASEDIR="${DATADIR}/lib"|g' \
		${WRKSRC}/dist/bin/hfsexplorer.sh

do-build:
	@cd ${WRKSRC} && ${SH} buildall.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/res
.for f in hfsx.sh resview.sh unhfs.sh
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} dist/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} dist/bin/hfsexplorer.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@cd ${WRKSRC} && ${INSTALL_DATA} dist/lib/*.jar ${STAGEDIR}${DATADIR}/lib
	@cd ${WRKSRC} && ${INSTALL_DATA} dist/res/icon.png ${STAGEDIR}${DATADIR}/res

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/dist/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
