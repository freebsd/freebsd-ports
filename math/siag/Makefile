# New ports collection makefile for:	siag (Scheme In A Grid)
# Date created:		27 Jan 1998
# Whom:			mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	siag
PORTVERSION=	3.3.8
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.siag.nu/pub/siag/ \
		ftp://ftp.edu.stockholm.se/pub/siag/ \
		ftp://ftp.icm.edu.pl/site/siag/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		Magick:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		mswordview:${PORTSDIR}/textproc/mswordview \
		catdoc:${PORTSDIR}/textproc/catdoc

GNU_CONFIGURE=	yes
MAKE_ARGS=	"-j 2"

CPPFLAGS+=	-I${LOCALBASE}/include -DX11BASE='\"${X11BASE}\"'

.if defined(GUILE)
LIB_DEPENDS+=	guile.9:${PORTSDIR}/lang/guile
.endif

.if !defined(NOGDBM)
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
CPPFLAGS+=	-DGDBM
.endif

.if !defined(NOT1)
LIB_DEPENDS+=	t1:${PORTSDIR}/devel/t1lib
.endif

.if !defined(NOTCL)
# Feel free to try other versions of TCL here:
LIB_DEPENDS+=	tcl83:${PORTSDIR}/lang/tcl83
CPPFLAGS+=	-I${LOCALBASE}/include/tcl8.3
CONFIGURE_ARGS+=--with-tcl=tcl83
.endif

CONFIGURE_ENV+= LOCALBASE=${LOCALBASE} \
			LDFLAGS=-L${LOCALBASE}/lib \
			CPPFLAGS="${CPPFLAGS}"

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=	xedplus.1 xfiler.1 gvu.1 siod.1 siag.1 pw.1 egon.1 \
	dummy_plugin.1 runcmd.1

post-install:
	# Examples  and  documentation went  into  ${PREFIX}/share/doc
	# Note, that the Siag's wordprocessor. the Pathetic Writer (or
	# pw)  is installed  in  ${PREFIX}/bin/pw.  Depending on  your
	# users'  PATH  it  may  or  may  not  interfere  with  simple
	# invocation of pw(8) (which is in /usr/sbin).
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
	# Fixing configure to look for Xaw3d instead of XawM
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure.XawM
	${SED} s/XawM/Xaw3d/g < ${WRKSRC}/configure.XawM > ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
