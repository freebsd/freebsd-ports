# $FreeBSD$

PORTNAME=	yubikey-manager-qt
DISTVERSIONPREFIX=	yubikey-manager-qt-
DISTVERSION=	1.0.1
CATEGORIES=	security

MAINTAINER=	daniel@shafer.cc
COMMENT=	Cross-platform application for configuring any YubiKey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yubikey-manager>0:security/py-yubikey-manager@${PY_FLAVOR} \
		pyotherside-qt5>0:devel/pyotherside-qt5

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yubikey-manager>0:security/py-yubikey-manager@${PY_FLAVOR} \
		pyotherside-qt5>0:devel/pyotherside-qt5

USES=		gl pkgconfig python:3.5+ qt:5 qmake shebangfix
USE_GL=		gl
USE_QT=		core declarative graphicaleffects gui network quickcontrols \
		quickcontrols2 svg widgets buildtools_build

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

SHEBANG_FILES=	ykman-gui/py/yubikey.py \
		ykman-cli/test.py \
		ykman-cli/py/cli.py \
		build_qrc.py

PLIST_FILES=	bin/ykman-gui \
		share/applications/ykman-gui.desktop \
		share/pixmaps/ykman.png

post-extract:
	@${REINPLACE_CMD} -e '/system/s|python|${PYTHON_CMD}|g' ${WRKSRC}/ykman-gui/ykman-gui.pro \
		${WRKSRC}/ykman-cli/ykman-cli.pro
	@${REINPLACE_CMD} -e 's|/usr/bin/ykman-gui|${PREFIX}/bin/ykman-gui|g' ${WRKSRC}/resources/linux/AppRun
	@${REINPLACE_CMD} -e 's|target.path = /usr/bin|target.path = ${PREFIX}/bin|g' ${WRKSRC}/ykman-gui/deployment.pri

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/ykman-gui.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/icons/ykman.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
