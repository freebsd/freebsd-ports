PORTNAME=	kddockwidgets
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	KDAB's Dock Widget Framework for Qt
WWW=		https://www.kdab.com/development-resources/qt-tools/kddockwidgets/

LICENSE=	GPLv2+

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		cmake:testing qt:5
USE_QT=		core declarative gui network quickcontrols2 widgets x11extras \
		buildtools:build qmake:build testlib:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	KDDockWidgets

CMAKE_TESTING_ON=	KDDockWidgets_TESTS KDDockWidgets_DEVELOPER_MODE

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
