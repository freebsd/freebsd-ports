# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	saga
PORTVERSION=	2.0.8
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]*$//}/SAGA%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	System for Automated Geoscientific Analyses

LICENSE=	GPLv2

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal:${PORTSDIR}/graphics/gdal \
		jasper:${PORTSDIR}/graphics/jasper \
		tiff:${PORTSDIR}/graphics/tiff \
		iodbc:${PORTSDIR}/databases/libiodbc \
		las:${PORTSDIR}/devel/liblas \
		opencv_legacy:${PORTSDIR}/graphics/opencv

USE_WX=		2.8
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GCC=	any
USE_AUTOTOOLS=	libtool
CFLAGS+=	-I${LOCALBASE}/include
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_DOS2UNIX=	dlg_about.cpp

MAN1=		saga_cmd.1 saga_gui.1

DESKTOP_ENTRIES=	"SAGA GIS" "${COMMENT}" "${DATADIR}/saga_icon_32.xpm" \
			"saga_gui" "Science;Geoscience;Math;" true

OPTIONS_DEFINE=	UNICODE PYTHON HARU VIGRA
OPTIONS_DEFAULT=	UNICODE PYTHON
NO_OPTIONS_SORT=	yes
UNICODE_DESC=	Enable Unicode Support
HARU_DESC=	Enable Haru Free PDF Library
VIGRA_DESC=	Enable 'Vision with Generic Algorithms' Library

.include <bsd.port.options.mk>

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.if ${PORT_OPTIONS:MUNICODE}
WITH_UNICODE=	yes
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--enable-python
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
USE_PYTHON=	2.6-2.7
PLIST_SUB+=	SAGA_PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	SAGA_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MHARU}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhpdf.so:${PORTSDIR}/print/libharu
RUN_DEPENDS+=	${LOCALBASE}/lib/libhpdf.so:${PORTSDIR}/print/libharu
PLIST_SUB+=	HARU=""
.else
PLIST_SUB+=	HARU="@comment "
.endif

.if ${PORT_OPTIONS:MVIGRA}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libvigraimpex.so:${PORTSDIR}/graphics/vigra
RUN_DEPENDS+=	${LOCALBASE}/lib/libvigraimpex.so:${PORTSDIR}/graphics/vigra
PLIST_SUB+=	VIGRA=""
.else
PLIST_SUB+=	VIGRA="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/-lcv/-lopencv_legacy/g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/modules_images/modules_opencv/opencv/Makefile.in
	@for f in `${FIND} '${WRKSRC}' -name Makefile.in` \
		${WRKSRC}/configure; do \
		${REINPLACE_CMD} -e's|wx-config |${WX_CONFIG} |g' "$$f"; \
	done
.if ${ARCH} == "i386" || ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga_tip.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/xpm/saga_icon_32.xpm ${DATADIR}
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${PREFIX}/lib/saga/*.la
	@${RM} ${PREFIX}/lib/saga/*.a
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
