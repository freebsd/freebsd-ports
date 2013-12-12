# Created by: gahr
# $FreeBSD$

PORTNAME=	carve
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A fast, robust constructive solid geometry library

LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	GUI

USES=		cmake:outsource
USE_GL=		glut
USE_LDCONFIG=	yes

LICENSE=	GPLv2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	libglui.so:${PORTSDIR}/devel/glui
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
