# New ports collection makefile for:	qhull
# Date created:				3 March 2004
# Whom:					pusto@web.de
#
# $FreeBSD$

PORTNAME=	qhull
PORTVERSION=	2011.1
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations and halfspaces

USE_CMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	qhull.1 rbox.1

CONFLICTS=	qhull-1.0*

post-patch:
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's#share/doc/packages#share/doc#g' \
		${WRKSRC}/CMakeLists.txt
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/libqhull6.so.6.2.0.1385 \
		${PREFIX}/lib/libqhull6.so.6

.include <bsd.port.mk>
