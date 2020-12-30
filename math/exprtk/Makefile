# $FreeBSD$

PORTNAME=	exprtk
DISTVERSION=	g20201207 # upstream rolls backwards commit dates, so use the port update date here
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ mathematical expression library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ArashPartow
GH_TAGNAME=	6dc74c3a6fcfc02feca9121b3cefdd43a8ed4e1e

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/exprtk.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/exprtk.hpp ${STAGEDIR}${PREFIX}/include

benchmark:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} pgo

.include <bsd.port.mk>
