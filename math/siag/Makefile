# New ports collection makefile for:	siag (Scheme In A Grid)
# Date created:		27 Jan 1998
# Whom:			mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	siag
PORTVERSION=	3.2.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.edu.stockholm.se/pub/siag/ \
		ftp://ftp.icm.edu.pl/site/siag/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d \
		Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		mswordview:${PORTSDIR}/textproc/mswordview \
		catdoc:${PORTSDIR}/textproc/catdoc

GNU_CONFIGURE=	yes
MAKEFLAGS=	"-j 2"

CPPFLAGS+=	-I${LOCALBASE}/include

.if defined(GUILE)
LIB_DEPENDS+=	guile.6:${PORTSDIR}/lang/guile
.endif

.if !defined(NOGDBM)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
CPPFLAGS+=	-DGDBM
.endif

.if !defined(NOT1)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libt1.a:${PORTSDIR}/devel/t1lib
.endif

.if !defined(NOTCL)
# Feel free to try other versions of TCL here:
LIB_DEPENDS+=	tcl82:${PORTSDIR}/lang/tcl82
CPPFLAGS+=	-I${LOCALBASE}/include/tcl8.2
CONFIGURE_ARGS+=--with-tcl=tcl82
.endif

CONFIGURE_ENV+= LOCALBASE=${LOCALBASE} \
			LDFLAGS=-L${LOCALBASE}/lib \
			CPPFLAGS="${CPPFLAGS}"

USE_X_PREFIX=	yes

MAN1=	xedplus.1 xfiler.1 gvu.1 siod.1 siag.1 pw.1 egon.1 dummy_plugin.1

post-install:
	# Examples  and  documentation went  into  ${PREFIX}/share/doc
	# Note, that the Siag's wordprocessor. the Pathetic Writer (or
	# pw)  is installed  in  ${PREFIX}/bin/pw.  Depending on  your
	# users'  PATH  it  may  or  may  not  interfere  with  simple
	# invocation of /usr/sbin/pw.
	@test -e ${PREFIX}/lib/X11/app-defaults/Siag && ${ECHO} \
		"It seems, you have old app-defaults file(s) from Siag.\
		 Consider removing it(them) if new siag fails to come up" |\
		fmt || ${TRUE}

post-patch:
	# Fixing makefiles to put docs in ${LOCALBASE}/share/doc/siag
	for m in `find ${WRKSRC} -name Makefile.in |\
			xargs ${GREP} -l doc\\/siag`; do \
		${MV} $$m $$m.orig; \
		${SED} s@doc/siag@share/doc/siag@ < $$m.orig > $$m; \
	done

.include <bsd.port.mk>
