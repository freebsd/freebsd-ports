# New ports collection makefile for:	siag (Scheme In A Grid)
# Date created:		27 Jan 1998
# Whom:			mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	siag
PORTVERSION=	3.4.10
CATEGORIES=	math
MASTER_SITES=	http://siag.nu/pub/siag/ \
		ftp://ftp.siag.nu/pub/siag/ \
		${MASTER_SITE_SUNSITE} \
		ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		sdb:${PORTSDIR}/databases/libsdb \
		Magick:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		wvHtml:${PORTSDIR}/textproc/wv \
		gv:${PORTSDIR}/print/gv \
		catdoc:${PORTSDIR}/textproc/catdoc

BUILD_DEPENDS+=	${LOCALBASE}/lib/libccm.a:${PORTSDIR}/math/ccmath
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm \
		t1:${PORTSDIR}/devel/t1lib \
		tcl83:${PORTSDIR}/lang/tcl83

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=tcl83 --with-xawm="-L${X11BASE} -lXaw3d" \
		--with-ndbm=gdbm \
		--without-gmp --with-sqlite --with-ccmath --with-t1lib
CPPFLAGS+=	-DGDBM -I${LOCALBASE}/include -DX11BASE='\"${X11BASE}\"' \
		-I${LOCALBASE}/include/tcl8.3
CONFIGURE_ENV+= LOCALBASE=${LOCALBASE} \
		LDFLAGS=-L${LOCALBASE}/lib \
		CPPFLAGS="${CPPFLAGS}"
MAKE_ARGS=	"-j 2"

.if defined(WITH_GUILE) || defined(GUILE)
LIB_DEPENDS+=	guile.10:${PORTSDIR}/lang/guile
.endif

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
	${PERL} -pi -e 's@doc/siag@share/doc/siag@' \
		`find ${WRKSRC} -name Makefile.in | \
			xargs ${GREP} -l doc\\/siag`
	# Fixing Makefile.in to remove hardcoded references to Xawm
	${PERL} -pi -e 's/ XawM//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
