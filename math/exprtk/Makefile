# $FreeBSD$

PORTNAME=	exprtk
DISTVERSION=	g20210303 # date when change was discovered because the upstream rolls back commit dates to Dec 31
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ mathematical expression library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ArashPartow
GH_TAGNAME=	ca5c577917646ddba3f71ce6d5dd7d01f351ee80

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/exprtk.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/exprtk.hpp ${STAGEDIR}${PREFIX}/include

benchmark:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} pgo

.include <bsd.port.mk>
