# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gchemutils
PORTVERSION=	0.14.16
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SAVANNAH/${PORTNAME}/${PORTVERSION:R}
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ classes and Gtk3 widgets related to chemistry

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data
LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libopenbabel.so:science/openbabel \
		libgoffice-0.10.so:devel/goffice010
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang desktop-file-utils gettext gl gmake gnome \
		libtool:keepla localbase:ldflags pathfix pkgconfig \
		shared-mime-info tar:xz xorg
USE_XORG=	x11
USE_GNOME=	cairo gnomedocutils gtk30 intlhack libgsf libxml2
USE_GL=		gl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
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

XUL_BROKEN=	XULrunner and non-Flash plugins are no longer supported
XUL_CONFIGURE_ON=--enable-mozilla-plugin \
		--with-mozilla-libdir=${PREFIX}/lib/xulrunner
XUL_CONFIGURE_OFF=--disable-mozilla-plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUMERIC} || exists(${LOCALBASE}/lib/libspreadsheet.so)
LIB_DEPENDS+=	libspreadsheet.so:math/gnumeric
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
