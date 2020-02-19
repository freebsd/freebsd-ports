# Created by: ijliao
# $FreeBSD$

PORTNAME=	matplotlib
DISTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
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
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>=1.0.0:math/py-kiwisolver@${PY_FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>0:devel/py-backports.functools_lru_cache@${PY_FLAVOR}

USES=		compiler:c++11-lib gettext gnome pkgconfig python shebangfix uniquefiles:dirs
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		EXAMPLES GTKBACKEND GTKAGGBACKEND \
			QT5AGGBACKEND TKAGGBACKEND WXAGGBACKEND
OPTIONS_DEFAULT=	GTKBACKEND GTKAGGBACKEND TKAGGBACKEND
OPTIONS_SUB=		yes
.if ${FLAVOR:Upy36:Mpy3*}
# x11-toolkits/py-gtk2, x11-toolkits/py-wxPython28 do not support Python 3
OPTIONS_EXCLUDE=	GTKBACKEND GTKAGGBACKEND WXAGGBACKEND
.endif

GTKBACKEND_DESC=	GTK backend support
GTKBACKEND_VARS=	GTK_BACKEND=True
GTKBACKEND_VARS_OFF=	GTK_BACKEND=False
GTKBACKEND_USES=	display
GTKBACKEND_USE=		GNOME=gtk20,pygtk2,cairo,gdkpixbuf2
GTKAGGBACKEND_DESC=	GTKAgg backend support
GTKAGGBACKEND_USES=	display
GTKAGGBACKEND_USE=	GNOME=gtk20,pygtk2,cairo,gdkpixbuf2
GTKAGGBACKEND_VARS=	GTKAGG_BACKEND=True
GTKAGGBACKEND_VARS_OFF=	GTKAGG_BACKEND=False
QT5AGGBACKEND_DESC=	Qt5Agg backend support
QT5AGGBACKEND_USES=	display pyqt:5
QT5AGGBACKEND_USE=	PYQT=sip,widgets
QT5AGGBACKEND_VARS=	QT5AGG_BACKEND=True
QT5AGGBACKEND_VARS_OFF=	QT5AGG_BACKEND=False
TKAGGBACKEND_DESC=	TKAgg backend support
TKAGGBACKEND_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKAGGBACKEND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKAGGBACKEND_USES=	display tk:run
TKAGGBACKEND_VARS=	TKAGG_BACKEND=True
TKAGGBACKEND_VARS_OFF=	TKAGG_BACKEND=False
WXAGGBACKEND_DESC=	WXAgg backend support
WXAGGBACKEND_USES=	display
WXAGGBACKEND_USE=	WX=2.8+
WXAGGBACKEND_CONFIGURE_ENV=	WX_CONFIG="${WX_CONFIG}"
WXAGGBACKEND_VARS=	WXAGG_BACKEND=True WX_COMPS=python:lib
WXAGGBACKEND_VARS_OFF=	WXAGG_BACKEND=False

PORTEXAMPLES=	*

post-extract:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} ${CHMOD} -x

post-patch:
	@${REINPLACE_CMD} -e 's|%%GTK_BACKEND%%|${GTK_BACKEND}|g' \
			 -e 's|%%GTKAGG_BACKEND%%|${GTKAGG_BACKEND}|g' \
			 -e 's|%%QT5AGG_BACKEND%%|${QT5AGG_BACKEND}|g' \
			 -e 's|%%TKAGG_BACKEND%%|${TKAGG_BACKEND}|g' \
			 -e 's|%%WXAGG_BACKEND%%|${WXAGG_BACKEND}|g' \
		${WRKSRC}/setup.cfg

post-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/web_backend/jquery-ui-1.12.1
	cd ${WRKSRC}/lib/matplotlib/backends/web_backend/jquery-ui-1.12.1 && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/web_backend/jquery-ui-1.12.1
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib -name '*.so' \
		| ${XARGS} ${STRIP_CMD}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
