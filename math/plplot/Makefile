# New ports collection makefile for:    plplot
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plplot
PORTVERSION=	5.1.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A scientific plotting package

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_REINPLACE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	F77="${FC}" FFLAGS="${FFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GDINCDIR="${LOCALBASE}/include/gd" \
		GDLIBDIR="${LOCALBASE}/lib" \
		XINCDIR="${X11BASE}/include" \
		XLIBDIR="${X11BASE}/lib" \
		PLPLOT_PREFIX="${DATADIR}" \
		DEMOS_DIR="${EXAMPLESDIR}" \
		INFO_DIR="${PREFIX}/info" \
		M4="${LOCALBASE}/bin/gm4"
CONFIGURE_ARGS=	--disable-python --disable-octave --with-double
INSTALLS_SHLIB=	yes

.if defined(WITH_TCLTK)
LIB_DEPENDS+=	itk32.1:${PORTSDIR}/x11-toolkits/itk
CONFIGURE_ENV+=	ITCLINCDIR="${LOCALBASE}/include/itcl3.2" \
		ITCLLIBDIR="${LOCALBASE}/lib" \
		ITCLLIBSTR="-litcl32" \
		ITKINCDIR="${LOCALBASE}/include/itk3.2" \
		ITKLIBDIR="${LOCALBASE}/lib" \
		ITKLIBSTR="-litk32" \
		TCLINCDIR="${LOCALBASE}/include/tcl8.3" \
		TCLLIBDIR="${LOCALBASE}/lib" \
		TCLLIBSTR="-ltcl83" \
		TKINCDIR="${LOCALBASE}/include/tk8.3" \
		TKLIBDIR="${LOCALBASE}/lib" \
		TKLIBSTR="-ltk83"
PLIST_SUB+=	TCLTK=""
.else
CONFIGURE_ARGS+=	--disable-itcl --disable-tcl --disable-tk
PLIST_SUB+=	TCLTK="@comment "
.endif

post-patch:
.for file in scripts/mktclIndex
	@${REINPLACE_CMD} -e 's|tclsh|${LOCALBASE}/bin/tclsh8.3|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
