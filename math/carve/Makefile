# New ports collection Makefile for:	carve
# Date created:				16 November 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	carve
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A fast, robust constructive solid geometry library

LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs

OPTIONS=	GUI "Enable GUI" off

USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
USE_GL=		glut
USE_LDCONFIG=	yes

LICENSE=	GPLv2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if defined(WITH_GUI)
LIB_DEPENDS+=	glui:${PORTSDIR}/devel/glui
PLIST_SUB+=	GUI=""
CMAKE_ARGS+=	-DCARVE_WITH_GUI:BOOL=true
.else
CONFIGURE_ARGS+=--with-gui=no
PLIST_SUB+=	GUI="@comment "
CMAKE_ARGS+=	-DCARVE_WITH_GUI:BOOL=false
.endif

post-install:
	${LN} -sf libcarve.so.${PORTVERSION} ${PREFIX}/lib/libcarve.so.${PORTVERSION:R:R}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/carve.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
