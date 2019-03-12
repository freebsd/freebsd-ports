# $FreeBSD$

PORTNAME=	yubioath-desktop
DISTVERSIONPREFIX=	yubioath-desktop-
DISTVERSION=	4.3.4
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	daniel@shafer.cc
COMMENT=	GUI for displaying OATH codes with a Yubikey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yubikey-manager>=0.7.0:security/py-yubikey-manager@${PY_FLAVOR} \
		pyotherside-qt5>0:devel/pyotherside-qt5 \
		RSA_SecurID_getpasswd:devel/libccid \
		libffi>0:devel/libffi \
		pcscd:devel/pcsc-lite \
		swig30>0:devel/swig30

USES=		compiler:c++11-lang desktop-file-utils gl python:3.5+ qmake qt:5 \
		shebangfix ssl
USE_GL=		gl
USE_QT=		core declarative gui network quickcontrols svg widgets buildtools_build

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

SHEBANG_FILES=	build_qrc.py \
		py/yubikey.py \
		compute-version.py

PLIST_FILES=	bin/yubioath-desktop \
		share/applications/yubioath-desktop.desktop \
		share/pixmaps/yubioath.png

post-patch:
	@${REINPLACE_CMD} -e '/buildqrc.commands/s|python|${PYTHON_CMD}|g' \
		-e '/PYTHON3_BINARY_NAME/s|python3|${PYTHON_CMD}|g' \
		-e '/system(python/s|python|${PYTHON_CMD}|g' \
		-e '/VERSION =/s|VERSION|#VERSION|g' \
		${WRKSRC}/yubioath-desktop.pro
	@${REINPLACE_CMD} -e '/version/s|python3|${PYTHON_CMD}|g' ${WRKSRC}/dev-util/package-sources.sh
	@${REINPLACE_CMD} -e 's|target.path = /usr/bin|target.path = ${PREFIX}/bin|g' ${WRKSRC}/deployment.pri

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/yubioath-desktop.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/icons/yubioath.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
