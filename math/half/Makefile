# $FreeBSD$

PORTNAME=	half
DISTVERSION=	2.1.0
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for half precision floating point arithmetic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/half.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/half.hpp ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
