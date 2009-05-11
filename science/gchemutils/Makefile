# New ports collection makefile for:	gchemutils
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gchemutils
PORTVERSION=	0.10.4
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/0.10
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	C++ classes and Gtk2 widgets related to chemistry

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		openbabel.3:${PORTSDIR}/science/openbabel \
		goffice-0.8.7:${PORTSDIR}/devel/goffice
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data

BROKEN=		does not compile with goffice-0.7.6

USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack libglade2 gnomedocutils
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-omf-dir=${PREFIX}/share/omf
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	gcrystal.schemas gchempaint.schemas gchempaint-arrows.schemas gchemutils.schemas

MAN1=		gchem3d.1 gchemcalc.1 gchempaint.1 gchemtable.1 gcrystal.1 gspectrum.1

PLIST_SUB=	VER=0.10

OPTIONS=	XUL "Build browser plugin (requires Xulrunner)" off

.include <bsd.port.pre.mk>

.if defined(WITH_XUL)
USE_GECKO=	xulrunner
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFIGURE_ARGS+=--enable-mozilla-plugin
PLIST_SUB+=	XUL=""
.else
CONFIGURE_ARGS+=--disable-mozilla-plugin
PLIST_SUB+=	XUL="@comment "
.endif

.if ${OSVERSION} < 700043
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
