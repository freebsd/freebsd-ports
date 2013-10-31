# Created by: pusto@web.de
# $FreeBSD$

PORTNAME=	qhull
PORTVERSION=	2012.1
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations, and halfspaces

USES=		cmake
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	qhull.1 rbox.1

CONFLICTS=	qhull-1.0* afni-[0-9]* qhull5-*

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's#share/man/man#man/man#g' \
		${WRKSRC}/CMakeLists.txt

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

.include <bsd.port.mk>
