# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tidy-html5
PORTVERSION=	5.0.0
CATEGORIES=	www

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tidy tidies HTML and XML documents

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	htacg
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	1e70fc6

USES=		cmake
USE_GNOME=	libxslt
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIB:BOOL=ON

PLIST_SUB=	VER=${PORTVERSION}

pre-configure:
	${REINPLACE_CMD} -e 's|build/cmake/||' ${WRKSRC}/test/testone.sh

post-install:
	# To avoid conflict ATM - to be removed later
	${MV} ${STAGEDIR}${PREFIX}/bin/tidy ${STAGEDIR}${PREFIX}/bin/tidy5
	${MV} ${STAGEDIR}${PREFIX}/lib/libtidy.so ${STAGEDIR}${PREFIX}/lib/libtidy5.so

regression-test:
	(cd ${WRKSRC}/test && ./testall.sh)

.include <bsd.port.mk>
