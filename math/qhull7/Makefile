PORTNAME=	qhull
DISTVERSIONPREFIX=	v
DISTVERSION=	7.3.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	math
PKGNAMESUFFIX=	7

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations, and halfspaces

LICENSE=	Qhull
LICENSE_NAME=	Qhull License
LICENSE_FILE=	${WRKSRC}/COPYING.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Conflicts with qhull

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CONFLICTS=	qhull8 afni qhull5

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/cmake/Qhull/QhullTargets-${CMAKE_BUILD_TYPE:tl}.cmake

.include <bsd.port.mk>
