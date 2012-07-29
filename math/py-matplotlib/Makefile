# ex:ts=8
# Ports collection makefile for:	py-matplotlib
# Date created:			Aug 4, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	matplotlib
PORTVERSION=	1.1.1
CATEGORIES=	math python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz
LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		png15:${PORTSDIR}/graphics/png
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=yes
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	GTKBACKEND	"GTK backend support"		ON \
		GTKAGGBACKEND	"GTKAgg backend support"	ON \
		TKAGGBACKEND	"TKAgg backend support"		ON \
		WXAGGBACKEND	"WXAgg backend support"		OFF

UNIQUENAME=	${PORTNAME}

.include <bsd.port.options.mk>

.if defined(PACKAGE_BUILDING) && \
    (defined(WITH_GTKBACKEND) || defined(WITH_GTKAGGBACKEND) || \
    defined(WITH_TKAGGBACKEND) || defined(WITH_WXAGGBACKEND))
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
.endif

.if defined(WITH_GTKBACKEND) || defined(WITH_GTKAGGBACKEND)
USE_GNOME=	gtk20 pygtk2
.endif

.if defined(WITH_GTKBACKEND) && !defined(WITHOUT_GTKBACKEND)
GTK_BACKEND=	True

PLIST_SUB+=	GTKBACKEND=""
.else
GTK_BACKEND=	False

PLIST_SUB+=	GTKBACKEND="@comment "
.endif

.if defined(WITH_GTKAGGBACKEND)
GTKAGG_BACKEND=	True

PLIST_SUB+=	GTKAGGBACKEND=""
.else
GTKAGG_BACKEND=	False

PLIST_SUB+=	GTKAGGBACKEND="@comment "
.endif

.if defined(WITH_TKAGGBACKEND)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_TCL_RUN=	yes
USE_TK_RUN=	yes

TKAGG_BACKEND=	True

PLIST_SUB+=	TKAGGBACKEND=""
.else
TKAGG_BACKEND=	False

PLIST_SUB+=	TKAGGBACKEND="@comment "
.endif

.if defined(WITH_WXAGGBACKEND)
USE_WX=		2.8+
WX_COMPS=	python:lib
CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

WXAGG_BACKEND=	True
.else
WXAGG_BACKEND=	False
.endif

.include <bsd.port.pre.mk>

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
post-extract:
	${CHMOD} -R ga+r ${WRKDIR}

# bsd.tcl.mk doesn't set TK_VER, so we use TCL_VER instead
post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			 -e 's|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|g' \
			 -e 's|%%TK_INCLUDEDIR%%|${TK_INCLUDEDIR}|g' \
			 -e 's|%%TCL_LIBDIR%%|${TCL_LIBDIR}|g' \
			 -e 's|%%TK_LIBDIR%%|${TK_LIBDIR}|g' \
			 -e 's|%%TCL_VER%%|${TCL_VER:S/.//}|g' \
			 -e 's|%%TK_VER%%|${TCL_VER:S/.//}|g' \
		${WRKSRC}/setupext.py
	${REINPLACE_CMD} -e 's|%%GTK_BACKEND%%|${GTK_BACKEND}|g' \
			 -e 's|%%GTKAGG_BACKEND%%|${GTKAGG_BACKEND}|g' \
			 -e 's|%%TKAGG_BACKEND%%|${TKAGG_BACKEND}|g' \
			 -e 's|%%WXAGG_BACKEND%%|${WXAGG_BACKEND}|g' \
		${WRKSRC}/setup.cfg

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
