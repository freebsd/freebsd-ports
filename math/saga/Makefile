# Ports collection makefile for:   saga
# Date created:        13 November 2009
# Whom:                Rainer Hurling <rhurlin@gwdg.de>
#
# $FreeBSD$
#

PORTNAME=	saga
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]*$//}/SAGA%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	System for Automated Geoscientific Analyses

LIB_DEPENDS=	proj.6:${PORTSDIR}/graphics/proj \
		gdal.16:${PORTSDIR}/graphics/gdal \
		jasper.4:${PORTSDIR}/graphics/jasper \
		tiff.4:${PORTSDIR}/graphics/tiff \
		iodbc.3:${PORTSDIR}/databases/libiodbc \
		las.1:${PORTSDIR}/devel/liblas \
		cv.2:${PORTSDIR}/graphics/opencv

USE_WX=		2.8
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
CFLAGS+=	-I${LOCALBASE}/include
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_DOS2UNIX=	dlg_about.cpp

MAN1=		saga_cmd.1 saga_gui.1

DESKTOP_ENTRIES=	"SAGA GIS" "${COMMENT}" "${DATADIR}/saga_icon_32.xpm" \
			"saga_gui" "Application;Math;" true

OPTIONS=	UNICODE "Enable Unicode Support" On \
		HARU "Enable Haru Free PDF Library (optional)" Off

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.if defined(WITH_UNICODE)
WITH_UNICODE=	yes
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if defined(WITH_HARU)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhpdf.so:${PORTSDIR}/print/libharu
RUN_DEPENDS+=	${LOCALBASE}/lib/libhpdf.so:${PORTSDIR}/print/libharu
PLIST_SUB+=	HARU=""
.else
PLIST_SUB+=	HARU="@comment "
.endif

post-patch:
	@for f in `${FIND} '${WRKSRC}' -name Makefile.in` \
		${WRKSRC}/configure; do \
		${REINPLACE_CMD} -e's|wx-config |${WX_CONFIG} |g' "$$f"; \
	done
	@${REINPLACE_CMD} -e 's|#if !defined(__APPLE__) && !defined(__BSD__)|#ifdef HAVE_MALLOC_H|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h \
		${WRKSRC}/src/modules_projection/pj_georeference/pj_georeference/lmdif0.c
	@${REINPLACE_CMD} -e 's,<cv.h>,<opencv/cv.h>,' \
		${WRKSRC}/src/modules_images/modules_opencv/opencv/opencv.h
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga_tip.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/xpm/saga_icon_32.xpm ${DATADIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
