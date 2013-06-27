# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gchemutils
PORTVERSION=	0.14.2
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION:R}
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ classes and Gtk3 widgets related to chemistry

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data
LIB_DEPENDS=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		openbabel:${PORTSDIR}/science/openbabel \
		goffice-0.10:${PORTSDIR}/devel/goffice010
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data

PORTSCOUT=	limitw:1,even

USE_XZ=		yes
USE_XORG=	x11
USE_GNOME=	gnomedocutils gtk30 intlhack libgsf libxml2
USE_GMAKE=	yes
USES=		desktop-file-utils gettext pathfix shared-mime-info
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-omf-dir=${PREFIX}/share/omf
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GLIB_SCHEMAS=	org.gnome.gchemutils.crystal.gschema.xml \
		org.gnome.gchemutils.gschema.xml \
		org.gnome.gchemutils.paint.gschema.xml \
		org.gnome.gchemutils.paint.plugins.arrows.gschema.xml

MAN1=		gchem3d.1 gchemcalc.1 gchempaint.1 gchemtable.1 gcrystal.1 \
		gspectrum.1

PLIST_SUB=	VER=0.14 GOFFICE=0.10

OPTIONS_DEFINE=	XUL
XUL_DESC=	Build browser plugin (requires libxul)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXUL}
USE_GECKO=	libxul
CONFIGURE_ARGS+=--enable-mozilla-plugin \
		--with-mozilla-libdir=${PREFIX}/lib/xulrunner
PLIST_SUB+=	XUL=""
.else
CONFIGURE_ARGS+=--disable-mozilla-plugin
PLIST_SUB+=	XUL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/libs/gcp/Makefile.in

.include <bsd.port.mk>
