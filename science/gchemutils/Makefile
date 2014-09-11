# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gchemutils
PORTVERSION=	0.14.7
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION:R}
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ classes and Gtk3 widgets related to chemistry

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data
LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libopenbabel.so:${PORTSDIR}/science/openbabel \
		libgoffice-0.10.so:${PORTSDIR}/devel/goffice010
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data

PORTSCOUT=	limitw:1,even

USE_XORG=	x11
USE_GNOME=	gnomedocutils gtk30 intlhack libgsf libxml2
USES=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig shared-mime-info tar:xz
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

VER=		${PORTVERSION:R}
PLIST_SUB=	VER=${VER} GOFFICE=0.10 VERSION=${PORTVERSION}

OPTIONS_DEFINE=	GNUMERIC XUL
OPTIONS_SUB=	yes
GNUMERIC_DESC=	Build gnumeric plugin
XUL_DESC=	Build browser plugin (requires libxul)

XUL_USES=	gecko
XUL_CONFIGURE_ON=--enable-mozilla-plugin \
		--with-mozilla-libdir=${PREFIX}/lib/xulrunner
XUL_CONFIGURE_OFF=--disable-mozilla-plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUMERIC} || exists(${LOCALBASE}/lib/libspreadsheet.so)
LIB_DEPENDS+=	libspreadsheet.so:${PORTSDIR}/math/gnumeric
PLIST_SUB+=	GNUMERIC=""
.else
PLIST_SUB+=	GNUMERIC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/libs/gcp/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*/*/*/*/*.so

.include <bsd.port.mk>
