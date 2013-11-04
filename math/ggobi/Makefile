# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	ggobi
PORTVERSION=	2.1.9
PORTREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.ggobi.org/downloads/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Data visualization system

USES=		pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gtk20 libxml2 gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl

CONFIGURE_ARGS+=	--with-all-plugins

ALL_TARGET=	all ggobirc

post-patch:
	@${REINPLACE_CMD} -e 's|ND_coord_i|ND_coord|' \
		${WRKSRC}/plugins/GraphLayout/graphviz.c
	@${REINPLACE_CMD} -e 's|#line 0|#line 1|' \
		${WRKSRC}/src/ggobi-data.c \
		${WRKSRC}/src/ggobi-renderer-cairo.c \
		${WRKSRC}/src/ggobi-renderer-factory.c \
		${WRKSRC}/src/ggobi-renderer.c

post-configure:
# build gets irritated by the presence of an external graphviz version
	@${REINPLACE_CMD} -e 's|#define HAVE_LIBGVC 1|/* #define HAVE_LIBGVC 1 */|' \
		${WRKSRC}/plugins/GraphLayout/config.h
	@${REINPLACE_CMD} -e 's|LIBGVC_CFLAGS = -I${LOCALBASE}/include/graphviz|LIBGVC_CFLAGS =|' \
		${WRKSRC}/plugins/GraphLayout/Makefile
	@${REINPLACE_CMD} -e 's|LIBGVC_LIBS = -L${LOCALBASE}/lib/graphviz -lgvc -lgraph -lcdt|LIBGVC_LIBS =|' \
		${WRKSRC}/plugins/GraphLayout/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/ggobi
	${INSTALL_DATA} ${WRKSRC}/ggobirc ${STAGEDIR}${PREFIX}/etc/xdg/ggobi/ggobirc.sample

.include <bsd.port.mk>
