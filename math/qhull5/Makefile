# New ports collection makefile for:	qhull
# Date created:				3 March 2004
# Whom:					pusto@web.de
#
# $FreeBSD$

PORTNAME=	qhull
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
DISTNAME=	${PORTNAME}-2003.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qhull computes convex hulls, Delaunay triangulations and halfspaces

USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.if !defined(NOPORTDOCS)
MAN1=		qhull.1 rbox.1
.endif

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|src html eg config|src config|"		\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-docDATA install-examplesDATA||"	\
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
