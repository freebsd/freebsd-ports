PORTNAME=	exprtk
DISTVERSION=	0.0.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Mathematical Expression Toolkit Library
WWW=		https://www.partow.net/programming/exprtk/index.html \
		https://github.com/ArashPartow/exprtk

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ArashPartow

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/exprtk.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/exprtk.hpp ${STAGEDIR}${PREFIX}/include

benchmark:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} pgo

.include <bsd.port.mk>
