PORTNAME=	pdfmixtool
DISTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	print graphics editors
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	dev@submerge.ch
COMMENT=	Application to split, merge, rotate and mix PDF files
WWW=		https://www.scarpetta.eu/pdfmixtool/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqpdf.so:print/qpdf
qt6_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake compiler:c++11-lang desktop-file-utils magick pkgconfig

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		buildtools:build core gui linguisttools:build qmake:build \
		svg widgets xml
.elif ${FLAVOR} == qt6
USES+=		gl qt:6
USE_GL=		gl opengl
USE_QT=		base tools:build svg
CMAKE_ARGS+=	-DQT_VERSION=6
.endif

USE_GITLAB=	yes
GL_ACCOUNT=	scarpetta
GL_TAGNAME=	35d482029881d9904c6e7487fe7572a3a5795406

LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	pdfmixtool-qt5 pdfmixtool-qt6

.include <bsd.port.mk>
