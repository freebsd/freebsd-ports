# Created by: ijliao
# $FreeBSD$

PORTNAME=	matplotlib
PORTVERSION=	1.4.3
CATEGORIES=	math python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users

LICENSE=	PSFL

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpng.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}parsing>=0:${PORTSDIR}/devel/py-parsing

USES=		pkgconfig python shebangfix uniquefiles:dirs
USE_PYTHON=	autoplist distutils
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	EXAMPLES GTKBACKEND GTKAGGBACKEND TKAGGBACKEND WXAGGBACKEND
OPTIONS_DEFAULT=	GTKBACKEND GTKAGGBACKEND TKAGGBACKEND
OPTIONS_SUB=		yes
GTKBACKEND_DESC=	GTK backend support
GTKBACKEND_VARS=	GTK_BACKEND=True
GTKBACKEND_VARS_OFF=	GTK_BACKEND=False
GTKBACKEND_USE=		GNOME=gtk20,pygtk2
GTKAGGBACKEND_DESC=	GTKAgg backend support
GTKAGGBACKEND_USE=	GNOME=gtk20,pygtk2
GTKAGGBACKEND_VARS=	GTKAGG_BACKEND=True
GTKAGGBACKEND_VARS_OFF=	GTKAGG_BACKEND=False
TKAGGBACKEND_DESC=	TKAgg backend support
TKAGGBACKEND_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
TKAGGBACKEND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
TKAGGBACKEND_USES=	tk:run
TKAGGBACKEND_VARS=	TKAGG_BACKEND=True
TKAGGBACKEND_VARS_OFF=	TKAGG_BACKEND=False
WXAGGBACKEND_DESC=	WXAgg backend support
WXAGGBACKEND_USE=	WX=2.8+
WXAGGBACKEND_VARS=	WX_COMPS=python:lib,WX_UNICODE=yes
WXAGGBACKEND_CONFIGURE_ENV=	WX_CONFIG="${WX_CONFIG}"
WXAGGBACKEND_VARS=	WXAGG_BACKEND=True
WXAGGBACKEND_VARS_OFF=	WXAGG_BACKEND=False

PORTEXAMPLES=	*

.if defined(PACKAGE_BUILDING)
GTKBACKEND_BUILD_DEPENDS=	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
GTKAGGBACKEND_BUILD_DEPENDS=	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
TKAGGBACKEND_BUILD_DEPENDS+=	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
WXAGGBACKEND_BUILD_DEPENDS=	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
.endif

post-extract:
	${CHMOD} -R ga+r ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			 -e 's|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|g' \
			 -e 's|%%TK_INCLUDEDIR%%|${TK_INCLUDEDIR}|g' \
			 -e 's|%%TCL_LIBDIR%%|${TCL_LIBDIR}|g' \
			 -e 's|%%TK_LIBDIR%%|${TK_LIBDIR}|g' \
			 -e 's|%%TCL_VER%%|${TCL_SHLIB_VER}|g' \
			 -e 's|%%TK_VER%%|${TK_SHLIB_VER}|g' \
		${WRKSRC}/setupext.py
	${REINPLACE_CMD} -e 's|%%GTK_BACKEND%%|${GTK_BACKEND}|g' \
			 -e 's|%%GTKAGG_BACKEND%%|${GTKAGG_BACKEND}|g' \
			 -e 's|%%TKAGG_BACKEND%%|${TKAGG_BACKEND}|g' \
			 -e 's|%%WXAGG_BACKEND%%|${WXAGG_BACKEND}|g' \
		${WRKSRC}/setup.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_image.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/_backend_agg.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/_gtkagg.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/_tkagg.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/_backend_gdk.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_qhull.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/ttconv.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_delaunay.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_png.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_tri.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_path.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/_cntr.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/ft2font.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
