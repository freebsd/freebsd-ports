# $FreeBSD$

PORTNAME=	exprtk
DISTVERSION=	g20200510
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ mathematical expression library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ArashPartow
GH_TAGNAME=	d81ac1a2ddd9877a7981d32c731fd9a75544ec68

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/exprtk.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/exprtk.hpp ${STAGEDIR}${PREFIX}/include

benchmark:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} pgo

.include <bsd.port.mk>
