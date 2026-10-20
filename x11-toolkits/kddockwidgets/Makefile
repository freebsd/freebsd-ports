PORTNAME=	kddockwidgets
DISTVERSION=	2.5.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/KDAB/KDDockWidgets/releases/download/v${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDAB's Dock Widget Framework for Qt
WWW=		https://www.kdab.com/development-resources/qt-tools/kddockwidgets/

LICENSE=	GPLv2+

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		cmake:testing qt:6
USE_QT=		base declarative
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	KDDockWidgets_TESTS KDDockWidgets_DEVELOPER_MODE

WRKSRC=		${WRKDIR}/KDDockWidgets-${DISTVERSION}

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
