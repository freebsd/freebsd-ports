PORTNAME=	yubioath-desktop
DISTVERSIONPREFIX=	yubioath-desktop-
DISTVERSION=	5.0.4
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	daniel@shafer.cc
COMMENT=	GUI for displaying OATH codes with a Yubikey
WWW=		https://developers.yubico.com/yubioath-desktop/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yubikey-manager>=0.7.0:security/py-yubikey-manager@${PY_FLAVOR} \
		pyotherside-qt5>0:devel/pyotherside-qt5 \
		RSA_SecurID_getpasswd:devel/libccid \
		libffi>0:devel/libffi \
		pcscd:devel/pcsc-lite \
		swig:devel/swig

USES=		compiler:c++11-lang desktop-file-utils gl python qmake qt:5 \
		shebangfix ssl
USE_GL=		gl
USE_QT=		core declarative gui network quickcontrols2 svg widgets buildtools:build

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

SHEBANG_FILES=	build_qrc.py \
		py/yubikey.py \

PLIST_FILES=	bin/yubioath-desktop \
		share/applications/com.yubico.yubioath.desktop \
		share/pixmaps/com.yubico.yubioath.png

post-patch:
	@${REINPLACE_CMD} -e '/PYTHON_CMD/s|python3|${PYTHON_CMD}|g' \
		${WRKSRC}/yubioath-desktop.pro
	@${REINPLACE_CMD} -e 's|target.path = /usr/bin|target.path = ${PREFIX}/bin|g' ${WRKSRC}/deployment.pri

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/com.yubico.yubioath.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/icons/com.yubico.yubioath.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
