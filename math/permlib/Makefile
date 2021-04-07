PORTNAME=	permlib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for permutation computations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	boost-libs>0:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	tremlin
GH_PROJECT=	PermLib

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${FIND} ${STAGEDIR}${PREFIX}/include -name "*.orig" -delete

.include <bsd.port.mk>
