PORTNAME=	kreport
DISTVERSION=	3.2.0
PORTREVISION=	11
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/stable/${PORTNAME}/src
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for creation of reports in multiple formats
WWW=		https://www.kexi-project.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libKPropertyCore3.so:x11-toolkits/kproperty

USES=		cmake compiler:c++11-lang gettext kde:5 python qt:5 tar:xz
USE_KDE=	config coreaddons widgetsaddons \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		core declarative gui network printsupport widgets xml \
		buildtools:build qmake:build

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Marble

post-extract:
	${CP} ${FILESDIR}/KReportGroupTracker.cpp ${WRKSRC}/src/renderer/scripting/KReportGroupTracker.cpp

.include <bsd.port.mk>
