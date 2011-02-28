# New ports collection makefile for:	gchemutils
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gchemutils
PORTVERSION=	0.12.6
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/0.12
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ classes and Gtk2 widgets related to chemistry

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		openbabel.3:${PORTSDIR}/science/openbabel \
		goffice-0.8.8:${PORTSDIR}/devel/goffice
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data

USE_BZIP2=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack intlhack gnomedocutils gtk20 libgsf
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-omf-dir=${PREFIX}/share/omf
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	gcrystal.schemas gchempaint.schemas gchempaint-arrows.schemas \
		gchemutils.schemas

MAN1=		gchem3d.1 gchemcalc.1 gchempaint.1 gchemtable.1 gcrystal.1 \
		gspectrum.1

PLIST_SUB=	VER=0.12 GOFFICE=0.8.13 GNUMERIC_VER=1.10.13

OPTIONS=	XUL "Build browser plugin (requires Xulrunner)" off

.include <bsd.port.pre.mk>

.if defined(WITH_XUL)
USE_GECKO=	libxul
CONFIGURE_ARGS+=--enable-mozilla-plugin
PLIST_SUB+=	XUL=""
.else
CONFIGURE_ARGS+=--disable-mozilla-plugin
PLIST_SUB+=	XUL="@comment "
.endif

.if exists(${LOCALBASE}/bin/gnumeric)
RUN_DEPENDS+=	gnumeric:${PORTSDIR}/math/gnumeric
PLIST_SUB+=	GNUMERIC=""
.else
PLIST_SUB+=	GNUMERIC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/libs/gcp/Makefile.in

.include <bsd.port.post.mk>
