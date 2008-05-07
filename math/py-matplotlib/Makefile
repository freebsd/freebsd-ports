# ex:ts=8
# Ports collection makefile for:	py-matplotlib
# Date created:			Aug 4, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	matplotlib
PORTVERSION=	0.91.2
CATEGORIES=	math python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	A plotting library uses a syntax familiar to matlab users

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${LOCALBASE}/lib/libagg.a:${PORTSDIR}/graphics/agg
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GNOME=	gtk20 pygtk2
USE_TCL_RUN=	yes
USE_TK_RUN=	yes
CFLAGS+=	-I${LOCALBASE}/include

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-patch:
	@${GREP} -lR "share/matplotlib" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s,share/matplotlib,share/py-matplotlib,g"
	${REINPLACE_CMD} \
		-e s,%%LOCALBASE%%,${LOCALBASE}, \
		-e s,%%TCL_INCLUDEDIR%%,${TCL_INCLUDEDIR}, \
		-e s,%%TK_INCLUDEDIR%%,${TK_INCLUDEDIR}, \
		-e s,%%USE_TK%%,${USE_TK}, \
		-e s,%%USE_TCL%%,${USE_TCL}, \
		${WRKSRC}/setupext.py

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
