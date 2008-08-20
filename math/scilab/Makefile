# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	math cad parallel
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	js@jeannot.org
COMMENT=	A free Matlab clone by INRIA & ENPC

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
    		pvm:${PORTSDIR}/net/pvm

USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
WANT_GNOME=	yes
USE_GNOME=	pkgconfig gtk20 libgtkhtml vte
USE_AUTOTOOLS=	autoconf:262

CONFIGURE_ARGS=	--with-tk \
		--with-tk-library=${LOCALBASE}/lib \
		--with-tk-include=${LOCALBASE}/include/tk8.4 \
		--with-tcl-library=${LOCALBASE}/lib \
		--with-tcl-include=${LOCALBASE}/include/tcl8.4 \
		--with-xaw3d \
		--x-include=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--without-java \
		--without-ocaml \
		--with-pvm-library=${LOCALBASE}/lib \
		--with-pvm-include=${LOCALBASE}/include \
		--with-gtk2

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CONFIGURE_ENV+=	F77=${F77} CFLAGS="${CFLAGS}" FFLAGS="${FFLAGS}" \
		PVM_ROOT=${LOCALBASE}/lib/pvm

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
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

WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
RUN_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
F77=		gfortran42
FC=		gfortran42
CONFIGURE_ARGS+=	--with-gfortran

.if ${ARCH} == "alpha" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		does not compile on alpha 5.x, ia64, sparc64
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

post-configure:
	${REINPLACE_CMD} -e 's|CC_OPTIONS)|CC_OPTIONS) ${CFLAGS}|g' \
	    ${WRKSRC}/routines/scicos/Makefile

pre-install:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${FIND} ${WRKSRC} -name .cvsignore -delete

.include <bsd.port.post.mk>
