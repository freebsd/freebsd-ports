# Created by: ijliao
# $FreeBSD$

PORTNAME=	matplotlib
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	http://cloud.github.com/downloads/matplotlib/matplotlib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig shebangfix
SHEBANG_FILES=	examples/pylab_examples/unicode_demo.py \
		examples/animation/old_animation/movie_demo.py
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYTHON_PY3K_PLIST_HACK=yes
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	GTKBACKEND GTKAGGBACKEND TKAGGBACKEND WXAGGBACKEND
OPTIONS_DEFAULT=	GTKBACKEND GTKAGGBACKEND TKAGGBACKEND
GTKBACKEND_DESC=	GTK backend support
GTKAGGBACKEND_DESC=	GTKAgg backend support
TKAGGBACKEND_DESC=	TKAgg backend support
WXAGGBACKEND_DESC=	WXAgg backend support

UNIQUENAME=	${PORTNAME}

.include <bsd.port.options.mk>

.if defined(PACKAGE_BUILDING) && \
    ( ${PORT_OPTIONS:MGTKBACKEND} || ${PORT_OPTIONS:MGTKAGGBACKEND} || \
    ${PORT_OPTIONS:MTKAGGBACKEND} || ${PORT_OPTIONS:MWXAGGBACKEND} )
BUILD_DEPENDS+=	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
.endif

.if ${PORT_OPTIONS:MGTKBACKEND} || ${PORT_OPTIONS:MGTKAGGBACKEND}
USE_GNOME=	gtk20 pygtk2
.endif

.if ${PORT_OPTIONS:MGTKBACKEND}
GTK_BACKEND=	True

PLIST_SUB+=	GTKBACKEND=""
.else
GTK_BACKEND=	False

PLIST_SUB+=	GTKBACKEND="@comment "
.endif

.if ${PORT_OPTIONS:MGTKAGGBACKEND}
GTKAGG_BACKEND=	True

PLIST_SUB+=	GTKAGGBACKEND=""
.else
GTKAGG_BACKEND=	False

PLIST_SUB+=	GTKAGGBACKEND="@comment "
.endif

.if ${PORT_OPTIONS:MTKAGGBACKEND}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

USES+=		tk:run

TKAGG_BACKEND=	True

PLIST_SUB+=	TKAGGBACKEND=""
.else
TKAGG_BACKEND=	False

PLIST_SUB+=	TKAGGBACKEND="@comment "
.endif

.if ${PORT_OPTIONS:MWXAGGBACKEND}
USE_WX=		2.8+
WX_COMPS=	python:lib
CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

WXAGG_BACKEND=	True
.else
WXAGG_BACKEND=	False
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
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

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
