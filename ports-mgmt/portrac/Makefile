PORTNAME=	portrac
PORTVERSION=	0.6
CATEGORIES=	ports-mgmt
DISTNAME=       v${PORTVERSION}
MASTER_SITES=	https://github.com/e-soul/portrac/archive/refs/tags/
WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	Mario.G.Pavlov@gmail.com
COMMENT=	Simple GUI tool for tracking port updates
WWW=		https://portrac.e-soul.org/

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lib gl qmake qt:5
USE_CXXSTD=	c++11
USE_GL=		gl
USE_QT=		buildtools:build core gui widgets

PLIST_FILES=	bin/portrac \
		share/portrac/portrac.png \
		share/portrac/up-to-date.png \
		share/portrac/updates-available.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/portrac ${STAGEDIR}${PREFIX}/bin && \
		${MKDIR} ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
