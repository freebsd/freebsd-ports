PORTNAME=	fluxengine
DISTVERSION=	572
CATEGORIES=	sysutils

MAINTAINER=	probono@puredarwin.org
COMMENT=	USB floppy disk interface for reading and writing non-PC disk formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		compiler:gcc-c++11-lib gmake ninja:build pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	davidgiven
GH_TAGNAME=	61ff48c

PLIST_FILES=	bin/brother120tool \
		bin/brother240tool \
		bin/fluxengine

post-patch:
	${REINPLACE_CMD} 's,^\(export CXX = \).*,\1${CXX},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/brother120tool ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/brother240tool ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/fluxengine ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
