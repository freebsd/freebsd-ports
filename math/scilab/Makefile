# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	math cad parallel
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	js@jeannot.org
COMMENT=	A free Matlab clone by INRIA & ENPC

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
WANT_GNOME=	yes
USE_AUTOTOOLS=	autoconf:259

CONFIGURE_ARGS=	--with-tk \
		--with-tk-library=${LOCALBASE}/lib \
		--with-tk-include=${LOCALBASE}/include/tk8.4 \
		--with-tcl-library=${LOCALBASE}/lib \
		--with-tcl-include=${LOCALBASE}/include/tcl8.4 \
		--with-xaw3d \
		--x-include=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--without-java \
		--without-ocaml

CONFIGURE_ENV+=	X11BASE=${X11BASE} F77=${F77} FFLAGS="${FFLAGS}"

OPTIONS=	GTK2	"Use Gtk+2 interface"	off \
		PVM	"Use PVM"	 	off

.include <bsd.port.pre.mk>

.if defined(WITH_PVM)
CONFIGURE_ARGS+=	--with-pvm-library=${LOCALBASE}/lib \
			--with-pvm-include=${LOCALBASE}/include
PVM_ROOT=	${LOCALBASE}/lib/pvm
CONFIGURE_ENV+=	PVM_ROOT=${PVM_ROOT}
RUN_DEPENDS+=	pvm:${PORTSDIR}/net/pvm
BUILD_DEPENDS+=	pvm:${PORTSDIR}/net/pvm
MAKE_ENV=	PVM_INCLUDE=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-pvm
.endif

.if defined(WITH_GTK2)
USE_GNOME=	pkgconfig gtk20 libgtkhtml vte
CONFIGURE_ARGS+=	--with-gtk2
PLIST_SUB+=	GTK2="" NOGTK2="@comment "
.if ${OSVERSION} < 500000 || exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif
.else
PLIST_SUB+=	GTK2="@comment " NOGTK2=""
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
CONFIGURE_ARGS+=	--with-atlas-library=${LOCALBASE}/lib
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lalapack -lcblas -lf77blas -latlas
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIBS?=	-llapack -lblas
.endif
MAKE_ENV+=	BLAS_LIBS="-L${LOCALBASE}/lib ${BLAS_LIBS}"

# Scilab broken with GCC 3.3 on FreeBSD 5.3
.if ${OSVERSION} >= 503000 && ${OSVERSION} < 600000
#USE_GCC=	3.2 #override FC and F77
BUILD_DEPENDS+=	gcc32:${PORTSDIR}/lang/gcc32
CC=		gcc32
CXX=		g++32
.endif

WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
RUN_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
F77=		gfortran42
FC=		gfortran42
CONFIGURE_ARGS+=	--with-gfortran

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102 || ${ARCH} == "ia64" || \
	${ARCH} == "sparc64" || ${ARCH} == "amd64" && ${OSVERSION} >= 700000
BROKEN=		does not compile on alpha 5.x, ia64, sparc64 or amd64 -CURRENT
.endif

post-patch:
	@# malloc.h -> stdlib.h conversions
	@${GREP} -lr "<malloc.h>" ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's/[<"]malloc.h[>"]/<stdlib.h>/'
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/%%PORTDOCS%%/#/' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's/%%PORTDOCS%%//' ${WRKSRC}/Makefile.in
.endif

pre-install:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${FIND} ${WRKSRC} -name .cvsignore -delete

.include <bsd.port.post.mk>
