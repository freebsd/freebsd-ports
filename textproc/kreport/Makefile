PORTNAME=	kreport
DISTVERSION=	3.2.0
PORTREVISION=	10
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

OPTIONS_DEFINE=		MARBLE
OPTIONS_DEFAULT=	MARBLE
OPTIONS_SUB=		yes

MARBLE_DESC=		Virtual globe and world atlas
MARBLE_USE=		kde=marble
MARBLE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Marble

.include <bsd.port.options.mk>

# These dependencies are only needed if the WEBENGINE option is enabled
# in astro/marble.
.if ${PORT_OPTIONS:MMARBLE} && exists(${LOCALBASE}/lib/marble/plugins/Photo.so)
USE_QT+=	location webchannel webengine
.endif

post-extract:
	${CP} ${FILESDIR}/KReportGroupTracker.cpp ${WRKSRC}/src/renderer/scripting/KReportGroupTracker.cpp

.include <bsd.port.mk>
