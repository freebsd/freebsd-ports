PORTNAME=	shelxle
DISTVERSION=	1.0.1664
CATEGORIES=	science # chemistry
MASTER_SITES=	SF/${PORTNAME}/code/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface for small-molecule structure refinement
WWW=		https://www.shelxle.org/shelx/eingabe.php

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang dos2unix gl qmake qt:5 tar:bz2
DOS2UNIX_FILES=	shelXle.pro
USE_QT=		core gui network opengl widgets buildtools:build
USE_GL=		gl

PLIST_FILES=	bin/shelxle \
		share/applications/shelxle.desktop \
		share/pixmaps/shelxle.png

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -o -name "*.h" | ${XARGS} ${REINPLACE_CMD} -e 's|NULL|nullptr|g'

.include <bsd.port.mk>
