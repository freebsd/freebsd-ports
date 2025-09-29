PORTNAME=	onedrivegui
DISTVERSION=	1.2.2
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

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_LANG=	python
SHEBANG_GLOB=	*.py

SUB_FILES=	onedrivegui.sh

post-patch:
	${REINPLACE_CMD} -i "" -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/src/global_config.py
	${RM} ${WRKSRC}/src/resources/OneDriveGUI.desktop.orig
	${RM} ${WRKSRC}/src/global_config.py.orig

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	@${MKDIR} ${STAGEDIR}${DATADIR}

	${INSTALL_DATA} ${WRKSRC}/src/resources/images/OneDriveGUI.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/onedrivegui.png
	${INSTALL_DATA} ${WRKSRC}/src/resources/OneDriveGUI.desktop ${STAGEDIR}${DESKTOPDIR}

	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} "resources settings ui utils" ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/src/*.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
