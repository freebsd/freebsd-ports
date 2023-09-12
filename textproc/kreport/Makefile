PORTNAME=		kreport
DISTVERSION=		3.2.0
PORTREVISION=	8
CATEGORIES=		textproc kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Framework for creation of reports in multiple formats
WWW=		https://www.kexi-project.org/

LIB_DEPENDS=		libKPropertyCore3.so:x11-toolkits/kproperty

USES=		cmake compiler:c++11-lang gettext kde:5 python qt:5 tar:xz
USE_KDE=	config coreaddons marble widgetsaddons \
		ecm:build
USE_QT=		core declarative gui location network printsupport webchannel \
		webengine widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=		WEBKIT
OPTIONS_SUB=		yes
WEBKIT_DESC=		Use obsolete qt5-webkit to build Browser Plugin
WEBKIT_USE=		QT5=webkit
WEBKIT_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebKitWidgets

CONFLICTS_INSTALL=	calligra-2*

post-extract:
	${CP} ${FILESDIR}/KReportGroupTracker.cpp ${WRKSRC}/src/renderer/scripting/KReportGroupTracker.cpp

.include <bsd.port.mk>
