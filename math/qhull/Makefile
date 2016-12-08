# Created by: pusto@web.de
# $FreeBSD$

PORTNAME=	qhull
PORTVERSION=	2015.2
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
DISTNAME=	${PORTNAME}-2015-src-7.2.0

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations, and halfspaces

USES=		cmake tar:tgz
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFLICTS=	qhull-1.0* afni-[0-9]* qhull5-*

OPTIONS_DEFINE=	DOCS

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt

post-patch:
	${REINPLACE_CMD} -e 's#share/man/man#man/man#g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
