PORTNAME=	kaidan
DISTVERSION=	0.9.1
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/unstable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User-friendly XMPP client for every device
WWW=		https://www.kaidan.im/

BUILD_DEPENDS=	kquickimageeditor>0:graphics/kquickimageeditor \
		kirigami-addons>0:x11-toolkits/kirigami-addons
RUN_DEPENDS=	kquickimageeditor>0:graphics/kquickimageeditor \
		kirigami-addons>0:x11-toolkits/kirigami-addons
LIB_DEPENDS=	libQXmppQt5.so:net-im/qxmpp@qt5 \
		libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 \
		pkgconfig qt:5 tar:xz
USE_KDE=	ecm kirigami2 notifications qqc2-desktop-style
USE_QT=		core dbus declarative gui location multimedia network \
		quickcontrols2 sql svg widgets xml \
		buildtools:build qmake:build

.include <bsd.port.mk>
