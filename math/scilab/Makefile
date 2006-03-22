# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	3.1.1
PORTREVISION=	2
CATEGORIES=	math cad parallel
MASTER_SITES=	http://scilabsoft.inria.fr/download/${PORTVERSION}/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	js@jeannot.org
COMMENT=	A free Matlab clone by INRIA & ENPC

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		lapack.3:${PORTSDIR}/math/lapack
BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		sabcmd:${PORTSDIR}/textproc/sablotron
RUN_DEPENDS+=	pvm:${PORTSDIR}/net/pvm \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84

PVM_ROOT=	${LOCALBASE}/lib/pvm

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
WANT_GNOME=	yes

CONFIGURE_ARGS=	--with-tk \
		--with-tk-library=${LOCALBASE}/lib \
		--with-tk-include=${LOCALBASE}/include/tk8.4 \
		--with-tcl-library=${LOCALBASE}/lib \
		--with-tcl-include=${LOCALBASE}/include/tcl8.4 \
		--with-pvm-library=${LOCALBASE}/lib \
		--with-pvm-include=${LOCALBASE}/include \
		--with-xaw3d \
		--x-include=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--without-java \
		--without-ocaml

CONFIGURE_ENV=	PVM_ROOT=${PVM_ROOT} X11BASE=${X11BASE} F77=${F77} FFLAGS="${FFLAGS}"
MAKE_ENV=	PVM_INCLUDE=${LOCALBASE}/include

PLIST_SUB=	PORTVERSION="${PORTVERSION}" DOCSDIR="share/doc/scilab"

OPTIONS=	ATLAS	"Use Atlas"		on \
		GTK2	"Adds Gtk+2 support"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
USE_GNOME=		pkgconfig gtk20 libgtkhtml vte
CONFIGURE_ARGS+=	--with-gtk2
PLIST_SUB+=		GTK2="" NOGTK2="@comment "
.if ${OSVERSION} < 500000
LIB_DEPENDS+=		readline.5:${PORTSDIR}/devel/readline
.endif
.else
PLIST_SUB+=		GTK2="@comment " NOGTK2=""
.endif

.if !defined(WITHOUT_ATLAS)
CONFIGURE_ARGS+=	--with-atlas-library=${LOCALBASE}/lib
LIB_DEPENDS+=		f77blas.1:${PORTSDIR}/math/atlas
.endif

# Scilab broken with GCC 3.3 on FreeBSD 5.3
.if ${OSVERSION} >= 503000 && ${OSVERSION} < 600000
USE_GCC=	3.2
.endif

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102 || ${ARCH} == "sparc64"
BROKEN=		does not compile on alpha 5.x or sparc64
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

.include <bsd.port.post.mk>
