PORTNAME=	onedrivegui
DISTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	simple GUI for OneDrive client with multi-account support
WWW=		https://github.com/bpozdena/OneDriveGUI

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	onedrive:net/onedrive \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	bpozdena
GH_PROJECT=	OneDriveGUI

USES=		desktop-file-utils python shebangfix
USE_PYTHON=	pep517

SHEBANG_LANG=	python
SHEBANG_GLOB=	*.py

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	onedrivegui.sh

post-extract:
	@${MV} ${WRKSRC}/src/onedrive_gui ${WRKSRC}/src/onedrivegui

post-patch:
	${REINPLACE_CMD} -i "" -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/src/onedrivegui/global_config.py
	${RM} ${WRKSRC}/src/onedrivegui/resources/OneDriveGUI.desktop.orig
	${RM} ${WRKSRC}/src/onedrivegui/global_config.py.orig

post-install:
.for RESO in 128 16 24 256 32 48 64 96
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps
	${INSTALL_DATA} ${WRKSRC}/src/onedrivegui/resources/images/hicolor/${RESO}x${RESO}/apps/OneDriveGUI.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}

	${INSTALL_DATA} ${WRKSRC}/src/onedrivegui/resources/images/OneDriveGUI.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/onedrivegui.png
	${INSTALL_DATA} ${WRKSRC}/src/onedrivegui/resources/OneDriveGUI.desktop ${STAGEDIR}${DESKTOPDIR}

	@cd ${WRKSRC}/src/onedrivegui && ${COPYTREE_SHARE} "resources" ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
