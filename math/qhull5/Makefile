# Created by: pusto@web.de
# $FreeBSD$

PORTNAME=	qhull
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
DISTNAME=	${PORTNAME}-2003.1
PKGNAMESUFFIX=	5

PATCH_SITES=		http://www.qhull.org/download/
PATCHFILES=		poly.c-qh_gethash.patch
PATCH_DIST_STRIP=	-p2

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations, and halfspaces

CONFLICTS=	qhull-2011* afni-[0-9]*

USES=		libtool gmake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-configure:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e "s|src html eg config|src config|"		\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-docDATA install-examplesDATA||"	\
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
