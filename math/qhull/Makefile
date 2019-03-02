# Created by: pusto@web.de
# $FreeBSD$

PORTNAME=	qhull
DISTVERSIONPREFIX=	v
DISTVERSION=	7.2.1
PORTEPOCH=	1
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

CONFLICTS=	qhull afni qhull5

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt

.include <bsd.port.mk>
