PORTNAME=		kreport
DISTVERSION=		3.2.0
PORTREVISION=	6
CATEGORIES=		textproc kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Framework for creation of reports in multiple formats
WWW=		https://www.kexi-project.org/

LIB_DEPENDS=		libKPropertyCore3.so:x11-toolkits/kproperty

USES=			cmake compiler:c++11-lang gettext kde:5 \
			python qt:5 tar:xz
USE_KDE=		config coreaddons ecm marble widgetsaddons
USE_QT=			core declarative gui location network webchannel \
			webengine webkit widgets xml \
			buildtools:build printsupport qmake:build

CONFLICTS_INSTALL=	calligra-2*

post-extract:
	${CP} ${FILESDIR}/KReportGroupTracker.cpp ${WRKSRC}/src/renderer/scripting/KReportGroupTracker.cpp

.include <bsd.port.mk>
