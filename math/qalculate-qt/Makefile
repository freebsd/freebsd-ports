PORTNAME=	qalculate-qt
PORTVERSION=	4.9.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	${FLAVOR:S/qt//}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (Qt frontend)
WWW=		https://qalculate.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot

FLAVORS=		qt6 qt5
FLAVOR?=		${FLAVORS:[1]}
qt5_CONFLICTS_INSTALL=	qalculate-qt qalculate-qt6
qt6_CONFLICTS_INSTALL=	qalculate-qt qalculate-qt5

USES=		compiler:c++11-lib gl pkgconfig qmake qt:${FLAVOR:S/qt//}
_USE_GL_qt5=	gl
_USE_GL_qt6=	opengl
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	buildtools:build linguisttools:build core gui network widgets
_USE_QT_qt6=	base tools:build
USE_QT=		${_USE_QT_${FLAVOR}}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
