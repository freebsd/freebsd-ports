# $FreeBSD$

PORTNAME=	portrac
PORTVERSION=	0.5
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://e-soul.org/distfiles/ \
		http://home.e-soul.org/~mgp/distfiles/

MAINTAINER=	Mario.G.Pavlov@gmail.com
COMMENT=	Simple GUI tool for tracking port updates

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_9=	does not build (lacking c++11 support)

PLIST_FILES=	bin/portrac \
		share/portrac/portrac.png \
		share/portrac/up-to-date.png \
		share/portrac/updates-available.png

USES=		compiler:c++11-lib qmake tar:bzip2
USE_CXXSTD=	c++11
USE_QT5=	widgets buildtools_build

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/portrac ${STAGEDIR}${PREFIX}/bin && \
		${MKDIR} ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
