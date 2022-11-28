PORTNAME=	qFlipper
PORTVERSION=	1.2.1
CATEGORIES=	sysutils

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Application for updating Flipper Zero firmware
WWW=		https://github.com/flipperdevices/qFlipper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf-nanopb.so:devel/nanopb

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	flipperdevices
USE_GL=		gl
USE_QT=		concurrent core declarative gui linguisttools network \
		quickcontrols2 serialport svg widgets buildtools:build

PLIST_FILES=	bin/qFlipper \
		bin/qFlipper-cli \
		lib/qt5/plugins/libflipperproto0.so \
		share/applications/qFlipper.desktop \
		share/icons/hicolor/512x512/apps/qFlipper.png

.include <bsd.port.mk>
