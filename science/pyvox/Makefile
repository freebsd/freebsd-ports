# ex:ts=8
# Ports collection Makefile for:	bblimage
# Date created:			Jul 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyvox
PORTVERSION=	0.72
CATEGORIES=	science
MASTER_SITES=	http://www.med.upenn.edu/bbl/downloads/pyvox/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of software tools for medical image processing

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-09-01

LICENSE=	MIT

LIB_DEPENDS=	lapack.4:${PORTSDIR}/math/lapack

GNU_CONFIGURE=		yes
LAPACK?=		-llapack -lblas
CONFIGURE_ARGS =	--with-lapack="${LAPACK}" --with-python="${PYTHON_CMD}"
CONFIGURE_ENV=		ac_cv_header_tgmath_h=no
USE_GMAKE=		yes
USE_LDCONFIG=		yes
USE_PYTHON=		2.5+

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.else
CONFIGURE_ARGS+=--with-x
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw
USE_MOTIF=	yes
USE_TK =	82+
CFLAGS+=	-DUSE_COMPOSITELESS_PHOTO_PUT_BLOCK -I${LOCALBASE}/include \
		-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}
PLIST_SUB+=	X11=""
.endif

MAN1=	affreg.1 anonavw.1 bredit.1 decomment.1 dumpavw.1 editavw.1 makeavw.1 pyvox.1 \
	reged.1 regedit.1 qdv.1
MAN5=	cdata.5 param.5

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e '\|pmw=yes|s|yes|no|' -e '\|tkinter=yes|s|yes|no|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '\|#include "tk.h"|d' ${WRKSRC}/include/pyvox.h
.else
	@${REINPLACE_CMD} -e 's|-ltk|&${USE_TK}|' \
		${WRKSRC}/Makefile.in
.endif

.if defined(MAINTAINER_MODE)
check regress regression-test test: build
	 @(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
	 ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} regress)
.endif

.include <bsd.port.post.mk>
