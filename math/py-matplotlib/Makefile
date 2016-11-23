# Created by: ijliao
# $FreeBSD$

PORTNAME=	matplotlib
PORTVERSION=	1.5.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users

LICENSE=	PSFL

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libtcl86.so:lang/tcl86
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cycler>0:devel/py-cycler \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado

USE_GITHUB=	yes

USES=		compiler:c++11-lib gettext pkgconfig python:2.7 shebangfix uniquefiles:dirs
USE_PYTHON=	autoplist distutils
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		EXAMPLES GTKBACKEND GTKAGGBACKEND QT4AGGBACKEND \
			QT5AGGBACKEND TKAGGBACKEND WXAGGBACKEND
OPTIONS_DEFAULT=	GTKBACKEND GTKAGGBACKEND TKAGGBACKEND
OPTIONS_SUB=		yes
GTKBACKEND_DESC=	GTK backend support
GTKBACKEND_VARS=	GTK_BACKEND=True
GTKBACKEND_VARS_OFF=	GTK_BACKEND=False
GTKBACKEND_USE=		GNOME=gtk20,pygtk2,cairo,gdkpixbuf2
GTKAGGBACKEND_DESC=	GTKAgg backend support
GTKAGGBACKEND_USE=	GNOME=gtk20,pygtk2,cairo,gdkpixbuf2
GTKAGGBACKEND_VARS=	GTKAGG_BACKEND=True
GTKAGGBACKEND_VARS_OFF=	GTKAGG_BACKEND=False
QT4AGGBACKEND_DESC=	Qt4Agg backend support
QT4AGGBACKEND_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:x11-toolkits/py-qt4-gui
QT4AGGBACKEND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:x11-toolkits/py-qt4-gui
QT4AGGBACKEND_VARS=	QT4AGG_BACKEND=True
QT4AGGBACKEND_VARS_OFF=	QT4AGG_BACKEND=False
QT5AGGBACKEND_DESC=	Qt5Agg backend support
QT5AGGBACKEND_BUILD_DEPENDS= 	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:devel/py-sip ${PYTHON_PKGNAMEPREFIX}qt5-widgets>=5.5.1:x11-toolkits/py-qt5-widgets
QT5AGGBACKEND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:devel/py-sip ${PYTHON_PKGNAMEPREFIX}qt5-widgets>=5.5.1:x11-toolkits/py-qt5-widgets
QT5AGGBACKEND_VARS=	QT5AGG_BACKEND=True
QT5AGGBACKEND_VARS_OFF=	QT5AGG_BACKEND=False
TKAGGBACKEND_DESC=	TKAgg backend support
TKAGGBACKEND_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter
TKAGGBACKEND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter
TKAGGBACKEND_USES=	tk:run
TKAGGBACKEND_VARS=	TKAGG_BACKEND=True
TKAGGBACKEND_VARS_OFF=	TKAGG_BACKEND=False
WXAGGBACKEND_DESC=	WXAgg backend support
WXAGGBACKEND_USE=	WX=2.8+
WXAGGBACKEND_CONFIGURE_ENV=	WX_CONFIG="${WX_CONFIG}"
WXAGGBACKEND_VARS=	WXAGG_BACKEND=True WX_COMPS=python:lib WX_UNICODE=yes
WXAGGBACKEND_VARS_OFF=	WXAGG_BACKEND=False

PORTEXAMPLES=	*

.if defined(PACKAGE_BUILDING)
GTKBACKEND_BUILD_DEPENDS=	Xvfb:x11-servers/xorg-vfbserver
GTKAGGBACKEND_BUILD_DEPENDS=	Xvfb:x11-servers/xorg-vfbserver
QT4AGGBACKEND_BUILD_DEPENDS+=	Xvfb:x11-servers/xorg-vfbserver
QT5AGGBACKEND_BUILD_DEPENDS+=	Xvfb:x11-servers/xorg-vfbserver
TKAGGBACKEND_BUILD_DEPENDS+=	Xvfb:x11-servers/xorg-vfbserver
WXAGGBACKEND_BUILD_DEPENDS=	Xvfb:x11-servers/xorg-vfbserver
.endif

post-extract:
	${FIND} ${WRKSRC} -name \*.py | ${XARGS} ${CHMOD} -x

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
			 -e 's|%%QT4AGG_BACKEND%%|${QT4AGG_BACKEND}|g' \
			 -e 's|%%QT5AGG_BACKEND%%|${QT5AGG_BACKEND}|g' \
			 -e 's|%%TKAGG_BACKEND%%|${TKAGG_BACKEND}|g' \
			 -e 's|%%WXAGG_BACKEND%%|${WXAGG_BACKEND}|g' \
		${WRKSRC}/setup.cfg

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib -name '*.so' \
		| ${XARGS} ${STRIP_CMD}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
