PORTNAME=		kreport
DISTVERSION=		3.2.0
PORTREVISION=	9
CATEGORIES=		textproc kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Framework for creation of reports in multiple formats
WWW=		https://www.kexi-project.org/

LIB_DEPENDS=		libKPropertyCore3.so:x11-toolkits/kproperty

USES=		cmake compiler:c++11-lang gettext kde:5 python qt:5 tar:xz
USE_KDE=	config coreaddons widgetsaddons \
		ecm:build
USE_QT=		core declarative gui location network printsupport webchannel \
		webengine widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	MARBLE
OPTIONS_DEFAULT=MARBLE
OPTIONS_SUB=	yes

MARBLE_DESC=	Virtual globe and world atlas
MARBLE_USE=	kde=marble
MARBLE_CMAKE_OFF=	-DMarble_FOUND:BOOL=OFF

CONFLICTS_INSTALL=	calligra-2*

post-extract:
	${CP} ${FILESDIR}/KReportGroupTracker.cpp ${WRKSRC}/src/renderer/scripting/KReportGroupTracker.cpp

.include <bsd.port.mk>
