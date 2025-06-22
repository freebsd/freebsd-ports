PORTNAME=	kddockwidgets
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDAB's Dock Widget Framework for Qt
WWW=		https://www.kdab.com/development-resources/qt-tools/kddockwidgets/

LICENSE=	GPLv2+

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		cmake:testing compiler:c++17-lang qt:6
USE_QT=		base declarative
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	KDDockWidgets

CMAKE_ON=		KDDockWidgets_QT6
CMAKE_TESTING_ON=	KDDockWidgets_TESTS KDDockWidgets_DEVELOPER_MODE

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
