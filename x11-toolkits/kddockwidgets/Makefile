PORTNAME=	kddockwidgets
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	KDAB's Dock Widget Framework for Qt
WWW=		https://www.kdab.com/development-resources/qt-tools/kddockwidgets/

LICENSE=	GPLv2+

USES=		cmake:testing qt:5
USE_QT=		core gui widgets x11extras buildtools:build qmake:build testlib:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	KDDockWidgets

CMAKE_TESTING_ON=	KDDockWidgets_TESTS # tests aren't built, see https://github.com/KDAB/KDDockWidgets/issues/333

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
