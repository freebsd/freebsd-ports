PORTNAME=	qalculate-qt
PORTVERSION=	4.1.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (Qt frontend)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++11-lib gl pkgconfig qmake qt:5
USE_GL=		gl
USE_QT=		buildtools_build linguisttools_build core gui network widgets

QMAKE_ARGS=	MAN_DIR="${PREFIX}/man"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
