# New ports collection makefile for:    plplot
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plplot
PORTVERSION=	5.3.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific plotting package

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl \
		gd.4:${PORTSDIR}/graphics/gd

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GDINCDIR="${LOCALBASE}/include" \
		GDLIBDIR="${LOCALBASE}/lib" \
		M4="${LOCALBASE}/bin/gm4"
CONFIGURE_ARGS=	--disable-cgm --disable-java --disable-octave \
		--with-ltdlsystem --without-qhull
INSTALLS_SHLIB=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		plm2gif.1 plplot_libtool.1 plpr.1 pltek.1 pstex2eps.1

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.else
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.endif

.if !defined(WITHOUT_PTHREAD)
CONFIGURE_ARGS+=	--with-pthreads
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_TCLTK)
.undef WITHOUT_X11
PKGNAMESUFFIX=	-tcltk
LIB_DEPENDS+=	itk32.1:${PORTSDIR}/x11-toolkits/itk
CONFIGURE_ENV+=	ITKINCDIR="${LOCALBASE}/include/itk3.2" \
		ITKLIBDIR="${LOCALBASE}/lib" \
		TKINCDIR="${LOCALBASE}/include/tk8.3" \
		TKPRIVATEINCDIR="${LOCALBASE}/include/tk8.3/generic" \
		TKLIBDIR="${LOCALBASE}/lib" \
		ITCLINCDIR="${LOCALBASE}/include/itcl3.2" \
		ITCLLIBDIR="${LOCALBASE}/lib" \
		TCLINCDIR="${LOCALBASE}/include/tcl8.3" \
		TCLPRIVATEINCDIR="${LOCALBASE}/include/tcl8.3/generic" \
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
	@${ECHO_MSG} "	WITHOUT_X11=yes		Turns off X11 support"
	@${ECHO_MSG} "	WITHOUT_PTHREAD=yes	Turns off pthread support"
	@${ECHO_MSG} "	WITH_PYTHON=yes		Turns on Python support"
	@${ECHO_MSG} "	WITH_TCLTK=yes		Turns on Tcl/Tk support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-litk$$|-litk32|g ; \
		 s|-ltk$$|-ltk83|g ; \
		 s|-litcl$$|-litcl32|g ; \
		 s|-ltcl$$|-ltcl83|g ; \
		 s|-lpthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| tclsh | ${LOCALBASE}/bin/tclsh8.3 |g' \
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
