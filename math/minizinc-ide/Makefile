PORTNAME=	minizinc-ide
DISTVERSION=	2.6.0
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IDE for MiniZinc, a constraint modeling language

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	minizinc:math/minizinc

USES=		gl compiler:c++11-lang qmake qt:5
USE_QT=		core declarative gui location network printsupport sql webchannel webengine websockets widgets buildtools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	MiniZinc
GH_PROJECT=	MiniZincIDE

USE_GITLAB=	nodefault
GL_TUPLE=	minizinc:cp-profiler-integration:f16b3132df33b3f258971f36dbe5e909983381c9:cp/cp-profiler/src/cpp-integration

PLIST_FILES=	bin/MiniZincIDE \
		share/pixmaps/minizinc_icon.png

DESKTOP_ENTRIES=	"MiniZinc" "Constraint modeling language" "${PREFIX}/share/pixmaps/minizinc_icon.png" "MiniZincIDE" "Science;Development;Education;" ""

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/minizinc_icon.png

.include <bsd.port.mk>
