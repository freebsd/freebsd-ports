PORTNAME=	qalculate-qt
PORTVERSION=	4.2.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/

PATCH_SITES=	https://github.com/Qalculate/${PORTNAME}/commit/
PATCHFILES+=	a8bb789828cf21ad0551dd4b1757984b57d8e76b.patch:-p1 #Add missing header
PATCHFILES+=	fa69618d42b133e5942c4bb86efe2838b61af935.patch:-p1 #Fix version string

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (Qt frontend)
WWW=		https://qalculate.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++11-lib gl pkgconfig qmake qt:5
USE_GL=		gl
USE_QT=		buildtools_build linguisttools_build core gui network widgets

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
