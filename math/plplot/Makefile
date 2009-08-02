# New ports collection makefile for:    plplot
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plplot
PORTVERSION=	5.8.0
PORTREVISION=	3
CATEGORIES=	math science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific plotting package

LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode \
		gd.4:${PORTSDIR}/graphics/gd \
		qhull.5:${PORTSDIR}/math/qhull

USE_AUTOTOOLS=	libltdl:22
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--disable-cgm --disable-java --disable-octave \
		--with-gd-incdir=${LOCALBASE}/include \
		--with-gd-libdir=${LOCALBASE}/lib \
		--with-freetype-font-dir=${LOCALBASE}
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		plm2gif.1 plplot_libtool.1 plpr.1 pltek.1 pstex2eps.1

.if !defined(WITHOUT_PTHREAD)
CONFIGURE_ARGS+=	--with-pthreads
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.else
USE_XORG=	x11
LIB_DEPENDS+=	LASi.0:${PORTSDIR}/devel/lasi
PLIST_SUB+=	X11=""
.endif

.if defined(WITH_FORTRAN)
PKGNAMESUFFIX=	-fortran
USE_FORTRAN=	yes
CONFIGURE_ARGS+=	--enable-f95
PLIST_SUB+=	FORTRAN=""
.else
CONFIGURE_ARGS+=	--disable-f77
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if defined(WITH_GNOME)
.undef WITHOUT_X11
USE_GNOME=	libgnomeprintui libgnomeui
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
CONFIGURE_ARGS+=	--disable-gcw
.endif

.if defined(WITH_PYTHON)
BROKEN= 	does not build with PYTHON
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
CONFIGURE_ENV+=	PYTHON_VERSION="${PYTHON_VERSION}"
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	SVGALIB=""
.else
CONFIGURE_ARGS+=	--disable-linuxvga
PLIST_SUB+=	SVGALIB="@comment "
.endif

.if defined(WITH_TCLTK)
.undef WITHOUT_X11
PKGNAMESUFFIX=	-tcltk
LIB_DEPENDS+=	itk.3:${PORTSDIR}/x11-toolkits/itk
CONFIGURE_ENV+=	ITKINCDIR="${LOCALBASE}/include/itk3.3" \
		ITKLIBDIR="${LOCALBASE}/lib"	\
		TKINCDIR="${LOCALBASE}/include/tk8.4"	\
		TKPRIVATEINCDIR="${LOCALBASE}/include/tk8.4/generic"	\
		TKLIBDIR="${LOCALBASE}/lib"	\
		ITCLINCDIR="${LOCALBASE}/include/itcl3.3"	\
		ITCLLIBDIR="${LOCALBASE}/lib" \
		TCLINCDIR="${LOCALBASE}/include/tcl8.4" \
		TCLPRIVATEINCDIR="${LOCALBASE}/include/tcl8.4/generic"	\
		TCLLIBDIR="${LOCALBASE}/lib"
MAN1+=		plrender.1 plserver.1 pltcl.1
PLIST_SUB+=	TCLTK=""
.else
CONFIGURE_ARGS+=	--disable-itcl --disable-tcl --disable-tk
PLIST_SUB+=	TCLTK="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "PLplot has the following tunable options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_PTHREAD=yes	Turns off pthread support"
	@${ECHO_MSG} "	WITHOUT_X11=yes		Turns off X11 support"
	@${ECHO_MSG} "	WITH_FORTRAN=yes	Turns on Fortran support"
	@${ECHO_MSG} "	WITH_GNOME=yes		Turns on GNOME driver support"
	@${ECHO_MSG} "	WITH_PYTHON=yes		Turns on Python support"
	@${ECHO_MSG} "	WITH_SVGALIB=yes	Turns on SVGAlib support"
	@${ECHO_MSG} "	WITH_TCLTK=yes		Turns on Tcl/Tk support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-ltk$$|-ltk84|g ; \
		 s|-ltcl$$|-ltcl84|g ; \
		 s|-lpthread|${PTHREAD_LIBS:S/"//g}|g ; \
		 s|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| tclsh | ${LOCALBASE}/bin/tclsh8.4 |g' \
		${WRKSRC}/scripts/mktclIndex

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog Copyright FAQ NEWS PROBLEMS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/drivers/README.drivers \
		${DOCSDIR}/README.drivers
	${INSTALL_DATA} ${WRKSRC}/lib/csa/README \
		${DOCSDIR}/README.csa
	${INSTALL_DATA} ${WRKSRC}/lib/csa/README.1st \
		${DOCSDIR}/README.1st.csa
.endif

.include <bsd.port.mk>
