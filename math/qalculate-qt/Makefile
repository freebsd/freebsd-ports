PORTNAME=	qalculate-qt
PORTVERSION=	5.9.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (Qt frontend)
WWW=		https://qalculate.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++17-lang gl pkgconfig qmake qt:6
# Project does not set a c++ dialect, but it's better to not leave this
# undefined and left up to the whims of the compiler.
USE_CXXSTD=	c++17
USE_GL=		opengl
USE_QT=		base tools:build

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
