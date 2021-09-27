# Created by: pusto@web.de

PORTNAME=	qhull
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations, and halfspaces

LICENSE=	Qhull
LICENSE_NAME=	Qhull License
LICENSE_FILE=	${WRKSRC}/COPYING.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CONFLICTS=	qhull-7.* afni qhull5

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt

.include <bsd.port.mk>
