PORTNAME=	scidavis
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scientific data analysis and visualization

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgsl.so:math/gsl \
		libmuparser.so:math/muparser \
		libpng.so:graphics/png \
		libqwt5-qt5.so:x11-toolkits/qwt5-qt5 \
		libqwtplot3d-qt5.so:math/qwtplot3d \
		liborigin.so:math/liborigin

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig \
		qt:5 shared-mime-info
USE_GL=		gl glu
USE_QT=		core gui opengl printsupport svg widgets xml \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	highperformancecoder
CMAKE_ON=	ORIGIN_IMPORT
CMAKE_OFF=	DOWNLOAD_LINKS \
		SEARCH_FOR_UPDATES

OPTIONS_DEFINE=	DOCS NLS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

PYTHON_DESC=	Python scripting support
PYTHON_USES=	pyqt:5 python:3.6+
PYTHON_USE=	pyqt=core,gui,printsupport,sip,widgets
PYTHON_CMAKE_ON=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
			-DSCRIPTING_PYTHON=True
PYTHON_CMAKE_OFF=	-DSCRIPTING_PYTHON=False

post-install-PYTHON-on:
	${MV} ${STAGEDIR}${PREFIX}/etc/scidavisrc.py \
		${STAGEDIR}${PREFIX}/etc/scidavisrc.py.sample

.include <bsd.port.mk>
