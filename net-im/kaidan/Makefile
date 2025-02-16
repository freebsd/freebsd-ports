PORTNAME=	kaidan
DISTVERSION=	0.11.0
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User-friendly XMPP client for every device
WWW=		https://apps.kde.org/kaidan/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	kquickimageeditor-qt6>0:graphics/kquickimageeditor@qt6
LIB_DEPENDS=	libQXmppQt6.so:net-im/qxmpp \
		libicuuc.so:devel/icu \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	kquickimageeditor-qt6>0:graphics/kquickimageeditor@qt6

USES=		cmake compiler:c++23-lang desktop-file-utils gl kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	completion config coreaddons crash jobwidgets kio \
		kirigami-addons kirigami2 notifications prison \
		qqc2-desktop-style service solid widgetsaddons \
		ecm:build
USE_QT=		base declarative location multimedia positioning svg \
		tools:build
USE_XORG=	x11

.include <bsd.port.mk>
