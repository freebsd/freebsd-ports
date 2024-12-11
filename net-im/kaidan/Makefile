PORTNAME=	kaidan
DISTVERSION=	0.10.0
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User-friendly XMPP client for every device
WWW=		https://apps.kde.org/kaidan/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	kquickimageeditor>0:graphics/kquickimageeditor
LIB_DEPENDS=	libQXmppQt5.so:net-im/qxmpp@qt5 \
		libZXing.so:textproc/zxing-cpp \
		libicuuc.so:devel/icu
RUN_DEPENDS=	kquickimageeditor>0:graphics/kquickimageeditor

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons jobwidgets kio kirigami-addons \
		kirigami2 notifications qqc2-desktop-style service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus declarative gui location multimedia network \
		quickcontrols2 sql svg widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
