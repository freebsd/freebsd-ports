PORTNAME=	portrac
PORTVERSION=	0.5.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://e-soul.org/distfiles/ \
		http://home.e-soul.org/~mgp/distfiles/

MAINTAINER=	Mario.G.Pavlov@gmail.com
COMMENT=	Simple GUI tool for tracking port updates

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lib gl qmake qt:5 tar:bzip2
USE_CXXSTD=	c++11
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets

PLIST_FILES=	bin/portrac \
		share/portrac/portrac.png \
		share/portrac/up-to-date.png \
		share/portrac/updates-available.png

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/portrac ${STAGEDIR}${PREFIX}/bin && \
		${MKDIR} ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
